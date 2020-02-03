/**
 *
 * @author Paolo Masci, Patrick Oladimeji
 * @date 27/03/15 20:30:33 PM
 */
/*jslint vars: true, plusplus: true, devel: true, nomen: true, indent: 4, maxerr: 50 */
require.config({
    baseUrl: "./",
    paths: {
	       d3: './lib'
    }
});

require([
        "widgets/TouchscreenButton",
        "widgets/BasicDisplay",
        "widgets/TextSpeaker",
        "widgets/car/Gauge",
        "widgets/LED2",
        "widgets/car/Navigator",
        "widgets/ButtonActionsQueue",
        "websockets/FMIClient"
    ], function (
        TouchscreenButton,
        BasicDisplay,
        Speaker,
        Gauge,
        LED2,
        Navigator,
        ButtonActionsQueue,
        FMIClient
    ) {
        "use strict";
        var client = FMIClient.getInstance();
        var PVSioStateParser = require("util/PVSioStateParser");

        var DBG = false;
        var previous_mode; // this is used to keep track of mode changes, useful for voice feedback
        
        

		var canvas = document.getElementById("canvas1");
		var context = canvas.getContext('2d');

        // Function automatically invoked by PVSio-web when the back-end sends states updates
        function onMessageReceived(err, res) {
			//stop_tick;
            console.log(res);
            render(res);
            //start_tick(250);
        }

        var car = new Array(4);
        
        for(var i = 0; i < 4; ++i) {
			car[i] = {};
		}
        
        car[0].navigator = new Navigator("navDisplay_1",
			{ top: 235, left: 185, width: 300, height: 300 },
			{
				// autoscale: true,
                parent: "monitor",
		        maxX: 5,
                maxY: 5,
        		x0: 0,
        		y0: 0,
                lineColor: "red"
             });
        car[0].position = new BasicDisplay("position_1",
            { top: 285, left: 545, width: 200, height: 27 },
            {
                parent: "monitor",
                fontsize: 16,
                backgroundColor: "red"
            });
        car[1].navigator = new Navigator("navDisplay_2",
            { top: 235, left: 185, width: 300, height: 300 },
			{
				// autoscale: true,
                parent: "monitor",
		        maxX: 5,
                maxY: 5,
        		x0: 0,
        		y0: 0,
        		lineColor: "blue",
                backgroundColor: "transparent"
            });
        car[1].position = new BasicDisplay("position_2",
            { top: 332, left: 545, width: 200, height: 27 },
            {
                parent: "monitor",
                fontsize: 16,
                backgroundColor: "blue"
            });
        car[2].navigator = new Navigator("navDisplay_3",
            { top: 235, left: 185, width: 300, height: 300 },
			{
				// autoscale: true,
                parent: "monitor",
		        maxX: 5,
                maxY: 5,
        		x0: 0,
        		y0: 0,
                lineColor: "green",
                backgroundColor: "transparent"
            });
        car[2].position = new BasicDisplay("position_3",
            { top: 379, left: 545, width: 200, height: 27},
            {
                parent: "monitor",
                fontsize: 16,
                backgroundColor: "green"
            });
        car[3].navigator = new Navigator("navDisplay_4",
            { top: 235, left: 185, width: 300, height: 300 },
            {
				// autoscale: true,
                parent: "monitor",
				maxX: 5,
                maxY: 5,
				x0: 0,
				y0: 0,
                lineColor: "#FFA500",
                backgroundColor: "transparent"
             });
        car[3].position = new BasicDisplay("position_4",
			{ top: 421, left: 545, width: 200, height: 27},
            {
                parent: "monitor",
                fontsize: 16,
                backgroundColor: "#FFA500"
            });

        function speak(txt) {
            // if (responsiveVoice && typeof responsiveVoice.speak === "function") {
            //     responsiveVoice.speak(txt);
            // }
        }

        // Render car dashboard components
        function render(res) {
            car[0].navigator.reveal();
            car[1].navigator.reveal();
            car[2].navigator.reveal();
            car[3].navigator.reveal();

            // gauges
            if (res) {
                var ans = res.split(";");
                var state = {};
                var state_aux = {};
                var left = 0;
                var right = 0;

                state_aux = PVSioStateParser.parse(ans[0]);
                console.log(state_aux);
				if (state_aux) {
					
					//Map size
					var ms = PVSioStateParser.evaluate(state_aux["mapSize"]);
					var pos = PVSioStateParser.evaluate(state_aux["mapSize"]) / 2;
					var nRobots = PVSioStateParser.evaluate(state_aux["nRobots"]);
					var eP = PVSioStateParser.evaluate(state_aux["explorationPercentage"]);
					var finished = PVSioStateParser.evaluate(state_aux["finished"]);
					var pos_x = new Array(parseInt(nRobots)); 
					var pos_y = new Array(parseInt(nRobots));
					
					for(var i = 0; i < parseInt(nRobots); ++i) {
						pos_x[i] = PVSioStateParser.evaluate(state_aux["x_" + (i+1)]);
						pos_y[i] = PVSioStateParser.evaluate(state_aux["y_" + (i+1)]);
						car[i].navigator.render([{ x: (pos_x[i] * 10 / ms - 5), y: (pos_y[i] * 10 / ms - 5)}]);;
						car[i].position.render("(x: " + pos_x[i] + ", y: " + pos_y[i] + ")");
					}
					
					var div = document.getElementById("eP");
					div.innerHTML = "Exploration %: " + eP + "%";
					div = document.getElementById("info");
					div.innerHTML = "Simulation started";
                    
                    //Cell width
                    var cw = (300 / ms);
                    // Box width
					var bw = ms * cw;
					// Box height
					var bh = ms * cw;
					//Obstacles
					var obstacles = {x: [(PVSioStateParser.evaluate(state_aux["ox_1"]) - 1) * cw, 
										 (PVSioStateParser.evaluate(state_aux["ox_2"]) - 1) * cw,
										 (PVSioStateParser.evaluate(state_aux["ox_3"]) - 1) * cw,
										 (PVSioStateParser.evaluate(state_aux["ox_4"]) - 1) * cw,
										 (PVSioStateParser.evaluate(state_aux["ox_5"]) - 1) * cw,
										 (PVSioStateParser.evaluate(state_aux["ox_6"]) - 1) * cw,
										 (PVSioStateParser.evaluate(state_aux["ox_7"]) - 1) * cw,
										 (PVSioStateParser.evaluate(state_aux["ox_8"]) - 1) * cw,
										 (PVSioStateParser.evaluate(state_aux["ox_9"]) - 1) * cw,
										 (PVSioStateParser.evaluate(state_aux["ox_10"]) - 1) * cw
										], 
									 y: [(ms - PVSioStateParser.evaluate(state_aux["oy_1"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_2"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_3"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_4"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_5"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_6"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_7"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_8"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_9"])) * cw,
										 (ms - PVSioStateParser.evaluate(state_aux["oy_10"])) * cw,
										]
									};
					
					function drawBoard(){
						context.fill();
						context.beginPath();
						for (var i = 0; i <= bw; i += cw) {
							for (var j = 0; j <= bh; j += cw) {
								context.moveTo(i, 0);
								context.lineTo(i, bh);
								context.moveTo(0, j);
								context.lineTo(bw, j);9
							}
						}
						context.strokeStyle = "black";
						context.lineWidth = 1.5;
						context.stroke();
						
						for(i = 0; i < PVSioStateParser.evaluate(state_aux["nObstacles"]); i += 1) {
							if((obstacles.x[i] >= 0) && (obstacles.y[i] >= 0) && (obstacles.x[i] <= bw) && (obstacles.y[i] <= bh)) {
								context.rect(obstacles.x[i], obstacles.y[i], cw, cw);
								context.fillStyle = "black";
								context.fill();
							}
						}
					}
					
					drawBoard();
                }
            }
        }

        ButtonActionsQueue.getInstance().addListener("FMI_TRYING_TO_CONNECT", function (evt) {
            console.log("trying to connect...");
			car[0].navigator.resetDisplay({
				keepOldTrace: true,
                changeColor: false
            });
            car[1].navigator.resetDisplay({
                keepOldTrace: true,
                changeColor: false
            });
             car[2].navigator.resetDisplay({
                keepOldTrace: true,
                changeColor: false
            });
            car[3].navigator.resetDisplay({
               keepOldTrace: true,
               changeColor: false
           });
            previous_mode = null;
        });
        ButtonActionsQueue.getInstance().addListener("FMI_RECONNECTED", function (evt) {
            console.log("connected :)");
            speak("connected!");
        });
        ButtonActionsQueue.getInstance().addListener("FMI_CONNECTION_ERROR", function (evt) {
            console.log("connection error :((");
        });

        // Function used for polling the robot state at periodic intervals
        var tick;
        function start_tick(interval) {
            if (!tick) {
                tick = setInterval(function () {
					if(ButtonActionsQueue.getInstance().buffer.length==0)
                    ButtonActionsQueue.getInstance().queueGUIAction("refresh",onMessageReceived );
                }, interval);
            }
        }
        function stop_tick() {
            if (tick) {
                clearInterval(tick);
                tick = null;
            }
        }

        // -- dbg lines for testing
        // car.position.render("(0.138, -0.08)");
        // car.navigator.render([{ x:0, y:-.50 }, { x:-.100, y:-.50 }, { x:-.100, y:-.150 }, { x:.100, y:-.150 }, { x:.100, y:-.100 }, { x:.200, y:.50 }, { x:-.200, y:-.200 }]);
        // --

        // start the simulation
        render();
        start_tick(250); // tick interval is in milliseconds
});
