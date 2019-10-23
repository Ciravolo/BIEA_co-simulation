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

        // Function automatically invoked by PVSio-web when the back-end sends states updates
        function onMessageReceived(err, res) {
			//stop_tick;
            console.log(res);
            render(res);
            //start_tick(250);
        }

        var car = {};
        car.navigator_1 = new Navigator("navDisplay_1",
			{ top: 205, left: 155, width: 360, height: 360 },
			{
				// autoscale: true,
                parent: "monitor",
		        maxX: 10,
                maxY: 10,
        		x0: 0,
        		y0: 0,
                lineColor: "red"
             });
        car.position_1 = new BasicDisplay("position_1",
            { top: 285, left: 545, width: 200, height: 27 },
            {
                parent: "monitor",
                fontsize: 16,
                backgroundColor: "red"
            });
        car.navigator_2 = new Navigator("navDisplay_2",
            { top: 205, left: 155, width: 360, height: 360 },
			{
				// autoscale: true,
                parent: "monitor",
		        maxX: 10,
                maxY: 10,
        		x0: 0,
        		y0: 0,
        		lineColor: "blue",
                backgroundColor: "transparent"
            });
        car.position_2 = new BasicDisplay("position_2",
            { top: 332, left: 545, width: 200, height: 27 },
            {
                parent: "monitor",
                fontsize: 16,
                backgroundColor: "blue"
            });
         car.navigator_3 = new Navigator("navDisplay_3",
            { top: 205, left: 155, width: 360, height: 360 },
			{
				// autoscale: true,
                parent: "monitor",
		        maxX: 10,
                maxY: 10,
        		x0: 0,
        		y0: 0,
                lineColor: "green",
                backgroundColor: "transparent"
            });
        car.position_3 = new BasicDisplay("position_3",
            { top: 379, left: 545, width: 200, height: 27},
            {
                parent: "monitor",
                fontsize: 16,
                backgroundColor: "green"
            });
            car.navigator_4 = new Navigator("navDisplay_4",
               { top: 205, left: 155, width: 360, height: 360 },
         {
           // autoscale: true,
                   parent: "monitor",
               maxX: 10,
                   maxY: 10,
               x0: 0,
               y0: 0,
                   lineColor: "#FFA500",
                   backgroundColor: "transparent"
               });
           car.position_4 = new BasicDisplay("position_4",
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
            car.navigator_1.reveal();
            car.navigator_2.reveal();
            car.navigator_3.reveal();
            car.navigator_4.reveal();

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
					          var pos_x_1 = PVSioStateParser.evaluate(state_aux["x_1"]);
                    var pos_y_1 = PVSioStateParser.evaluate(state_aux["y_1"]);
                    car.navigator_1.render([{ x: pos_x_1, y: pos_y_1 }]);;
					          car.position_1.render("(x: " + pos_x_1 + ", y: " + pos_y_1 + ")");
                    var pos_x_2 = PVSioStateParser.evaluate(state_aux["x_2"]);
                    var pos_y_2 = PVSioStateParser.evaluate(state_aux["y_2"]);
                    car.navigator_2.render([{ x: pos_x_2, y: pos_y_2 }]);;
                    car.position_2.render("(x: " + pos_x_2 + ", y: " + pos_y_2 + ")");
                    var pos_x_3 = PVSioStateParser.evaluate(state_aux["x_3"]);
                    var pos_y_3 = PVSioStateParser.evaluate(state_aux["y_3"]);
                    car.navigator_3.render([{ x: pos_x_3, y: pos_y_3 }]);;
                    car.position_3.render("(x: " + pos_x_3 + ", y: " + pos_y_3 + ")");
                    var pos_x_4 = PVSioStateParser.evaluate(state_aux["x_4"]);
                    var pos_y_4 = PVSioStateParser.evaluate(state_aux["y_4"]);
                    car.navigator_4.render([{ x: pos_x_4, y: pos_y_4 }]);;
                    car.position_4.render("(x: " + pos_x_4 + ", y: " + pos_y_4 + ")");
                }
            }
        }

        ButtonActionsQueue.getInstance().addListener("FMI_TRYING_TO_CONNECT", function (evt) {
            console.log("trying to connect...");
			car.navigator_1.resetDisplay({
                keepOldTrace: true,
                changeColor: false
            });
            car.navigator_2.resetDisplay({
                keepOldTrace: true,
                changeColor: false
            });
             car.navigator_3.resetDisplay({
                keepOldTrace: true,
                changeColor: false
            });
            car.navigator_4.resetDisplay({
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
