function validateForm() {
	
	var i;
	var maxRobots = 4;
	var maxObstacles = 10;
	var mapSize = document.getElementById("mapSize");
	var nRobots = document.getElementById("nRobots");
	var nObstacles = document.getElementById("nObstacles");
	var rx = new Array(parseInt(nRobots.value));
	var ry = new Array(parseInt(nRobots.value));
	var ox = new Array(parseInt(nObstacles.value));
	var oy = new Array(parseInt(nObstacles.value));
	for(i = 0; i < parseInt(nRobots.value); ++i) {
		rx[i] = document.getElementById("coordinates1x" + (i+1));
		ry[i] = document.getElementById("coordinates1y" + (i+1));
	}
	for(i = 0; i < parseInt(nObstacles.value); ++i) {
		ox[i] = document.getElementById("coordinates2x" + (i+1));
		oy[i] = document.getElementById("coordinates2y" + (i+1));
	}
	var a1 = document.getElementById("a1");
	var a2 = document.getElementById("a2");
	var ertu = document.getElementById("ertu");
	var eta = document.getElementById("eta");
	var lambda = document.getElementById("lambda");
	var phi = document.getElementById("phi");
	var sRange = document.getElementById("sRange");
	var step = document.getElementById("step");
	var port = document.getElementById("port");
	
	if(mapSize.value === null || mapSize.value === "") {
		resetErrorMsg();

		document.getElementById("mapSize_error_msg").innerHTML = "Please enter the map size!";
		document.getElementById("mapSize").focus();
		document.getElementById("mapSize_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("mapSize_error_msg").style.display = "none";
	}	
	
	if(nRobots.value === null || nRobots.value === "") {
		resetErrorMsg();

		document.getElementById("nRobots_error_msg").innerHTML = "Please enter the number of robots!";
		document.getElementById("nRobots").focus();
		document.getElementById("nRobots_error_msg").style.display = "block";
		
		return false;
	}
	else{
		
		if(parseInt(nRobots.value) > parseInt(maxRobots)) {
			resetErrorMsg();

			document.getElementById("nRobots_error_msg").innerHTML = "The maximum number of robots is " + maxRobots;
			document.getElementById("nRobots").focus();
			document.getElementById("nRobots_error_msg").style.display = "block";
			
			return false;
		}
		else{
			document.getElementById("nRobots_error_msg").style.display = "none";
		}
	}	
	
	for(i = 0; i < parseInt(nRobots.value); ++i) {
		if(rx[i] != null) {
			if(rx[i].value === null || rx[i].value === "") {
				resetErrorMsg();

				document.getElementById(rx[i].id + "_error_msg").innerHTML = "Please enter a number!";
				document.getElementById(rx[i].id).focus();
				document.getElementById(rx[i].id + "_error_msg").style.display = "block";
				
				return false;
			}
			if(parseFloat(rx[i].value) > parseFloat(mapSize.value)) {
				resetErrorMsg();

				document.getElementById(rx[i].id + "_error_msg").innerHTML = "Invalid input! Remember that the map size is 10";
				document.getElementById(rx[i].id).focus();
				document.getElementById(rx[i].id + "_error_msg").style.display = "block";
				
				return false;
			}
			else{
				document.getElementById(rx[i].id + "_error_msg").style.display = "none";
			}	
		}
		
		if(ry[i] != null) {
			if(ry[i].value === null || ry[i].value === "") {
				resetErrorMsg();

				document.getElementById(ry[i].id + "_error_msg").innerHTML = "Please enter a number!";
				document.getElementById(ry[i].id).focus();
				document.getElementById(ry[i].id + "_error_msg").style.display = "block";
				
				return false;
			}
			else
			if(parseFloat(ry[i].value) > parseFloat(mapSize.value)) {
				resetErrorMsg();

				document.getElementById(ry[i].id + "_error_msg").innerHTML = "Invalid input! Remember that the map size is 10";
				document.getElementById(ry[i].id).focus();
				document.getElementById(ry[i].id + "_error_msg").style.display = "block";
				
				return false;
			}
			else{
				document.getElementById(ry[i].id + "_error_msg").style.display = "none";
			}
		}
	}
	
	if(nObstacles.value === null || nObstacles.value === "") {
		resetErrorMsg();

		document.getElementById("nObstacles_error_msg").innerHTML = "Please enter the number of obstacles!";
		document.getElementById("nObstacles").focus();
		document.getElementById("nObstacles_error_msg").style.display = "block";
		
		return false;
	}
	else{
		
		if(parseInt(nObstacles.value) > parseInt(maxObstacles)) {
			resetErrorMsg();

			document.getElementById("nObstacles_error_msg").innerHTML = "The maximum number of obstacles is " + maxObstacles;
			document.getElementById("nObstacles").focus();
			document.getElementById("nObstacles_error_msg").style.display = "block";
			
			return false;
		}
		else{
			document.getElementById("nObstacles_error_msg").style.display = "none";
		}
	}
	
	for(i = 0; i < parseInt(nObstacles.value); ++i) {
		if(ox[i] != null) {
			if(ox[i].value === null || ox[i].value === "") {
				resetErrorMsg();

				document.getElementById(ox[i].id + "_error_msg").innerHTML = "Please enter a number!";
				document.getElementById(ox[i].id).focus();
				document.getElementById(ox[i].id + "_error_msg").style.display = "block";
				
				return false;
			}
			if(parseFloat(ox[i].value) > parseFloat(mapSize.value)) {
				resetErrorMsg();

				document.getElementById(ox[i].id + "_error_msg").innerHTML = "Invalid input! Remember that the map size is 10";
				document.getElementById(ox[i].id).focus();
				document.getElementById(ox[i].id + "_error_msg").style.display = "block";
				
				return false;
			}
			else{
				document.getElementById(ox[i].id + "_error_msg").style.display = "none";
			}	
		}
		
		if(oy[i] != null) {
			if(oy[i].value === null || oy[i].value === "") {
				resetErrorMsg();

				document.getElementById(oy[i].id + "_error_msg").innerHTML = "Please enter a number!";
				document.getElementById(oy[i].id).focus();
				document.getElementById(oy[i].id + "_error_msg").style.display = "block";
				
				return false;
			}
			else
			if(parseFloat(oy[i].value) > parseFloat(mapSize.value)) {
				resetErrorMsg();

				document.getElementById(oy[i].id + "_error_msg").innerHTML = "Invalid input! Remember that the map size is 10";
				document.getElementById(oy[i].id).focus();
				document.getElementById(oy[i].id + "_error_msg").style.display = "block";
				
				return false;
			}
			else{
				document.getElementById(oy[i].id + "_error_msg").style.display = "none";
			}
		}
	}
	
	if(a1.value === null || a1.value === "") {
		resetErrorMsg();

		document.getElementById("a1_error_msg").innerHTML = "Please enter a1!";
		document.getElementById("a1").focus();
		document.getElementById("a1_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("a1_error_msg").style.display = "none";
	}
	
	if(a2.value === null || a2.value === "") {
		resetErrorMsg();

		document.getElementById("a2_error_msg").innerHTML = "Please enter a2!";
		document.getElementById("a2").focus();
		document.getElementById("a2_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("a2_error_msg").style.display = "none";
	}
	
	if(ertu.value === null || ertu.value === "") {
		resetErrorMsg();

		document.getElementById("ertu_error_msg").innerHTML = "Please enter the ERTU%!";
		document.getElementById("ertu").focus();
		document.getElementById("ertu_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("ertu_error_msg").style.display = "none";
	}
	
	if(eta.value === null || eta.value === "") {
		resetErrorMsg();

		document.getElementById("eta_error_msg").innerHTML = "Please enter eta!";
		document.getElementById("eta").focus();
		document.getElementById("eta_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("eta_error_msg").style.display = "none";
	}
	
	if(lambda.value === null || lambda.value === "") {
		resetErrorMsg();

		document.getElementById("lambda_error_msg").innerHTML = "Please enter lambda!";
		document.getElementById("lambda").focus();
		document.getElementById("lambda_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("lambda_error_msg").style.display = "none";
	}
	
	if(phi.value === null || phi.value === "") {
		resetErrorMsg();

		document.getElementById("phi_error_msg").innerHTML = "Please enter phi!";
		document.getElementById("phi").focus();
		document.getElementById("phi_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("phi_error_msg").style.display = "none";
	}
	
	if(sRange.value === null || sRange.value === "") {
		resetErrorMsg();

		document.getElementById("sRange_error_msg").innerHTML = "Please enter the spore range!";
		document.getElementById("sRange").focus();
		document.getElementById("sRange_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("sRange_error_msg").style.display = "none";
	}
	
	if(step.value === null || step.value === "") {
		resetErrorMsg();

		document.getElementById("step_error_msg").innerHTML = "Please enter the step size!";
		document.getElementById("step").focus();
		document.getElementById("step_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("step_error_msg").style.display = "none";
	}
	
	if(port.value === null || port.value === "") {
		resetErrorMsg();

		document.getElementById("port_error_msg").innerHTML = "Please enter the connection port!";
		document.getElementById("port").focus();
		document.getElementById("port_error_msg").style.display = "block";
		
		return false;
	}
	else{
		document.getElementById("port_error_msg").style.display = "none";
		createConfigurationFile();
	}
}

function resetErrorMsg(){	
	
	var i;
	var nRobots = document.getElementById("nRobots");
	var nObstacles = document.getElementById("nObstacles");
	var rx = new Array(parseInt(nRobots.value));
	var ry = new Array(parseInt(nRobots.value));
	var ox = new Array(parseInt(nObstacles.value));
	var oy = new Array(parseInt(nObstacles.value));
	for(i = 0; i < parseInt(nRobots.value); ++i) {
		rx[i] = document.getElementById("coordinates1x" + (i+1));
		ry[i] = document.getElementById("coordinates1y" + (i+1));
	}
	for(i = 0; i < parseInt(nObstacles.value); ++i) {
		ox[i] = document.getElementById("coordinates2x" + (i+1));
		oy[i] = document.getElementById("coordinates2y" + (i+1));
	}
	
	document.getElementById("mapSize_error_msg").style.display = "none";
	document.getElementById("nRobots_error_msg").style.display = "none";
	for(i = 0; i < parseInt(nRobots.value); ++i) {
		if(rx[i] != null) {
			document.getElementById(rx[i].id + "_error_msg").style.display = "none";
		}
		if(ry[i] != null) {
			document.getElementById(ry[i].id + "_error_msg").style.display = "none";
		}
	}
	document.getElementById("nObstacles_error_msg").style.display = "none";
	for(i = 0; i < parseInt(nObstacles.value); ++i) {
		if(ox[i] != null) {
			document.getElementById(ox[i].id + "_error_msg").style.display = "none";
		}
		if(oy[i] != null) {
			document.getElementById(oy[i].id + "_error_msg").style.display = "none";
		}
	}
	document.getElementById("a1_error_msg").style.display = "none";
	document.getElementById("a2_error_msg").style.display = "none";
	document.getElementById("ertu_error_msg").style.display = "none";
	document.getElementById("eta_error_msg").style.display = "none";
	document.getElementById("lambda_error_msg").style.display = "none";
	document.getElementById("phi_error_msg").style.display = "none";
	document.getElementById("sRange_error_msg").style.display = "none";
	document.getElementById("step_error_msg").style.display = "none";
	document.getElementById("port_error_msg").style.display = "none";
}

function createConfigurationFile() {
	var text = {"fmus":{  
					"{Robot1}":"Body_Block1.fmu", 
					"{Robot2}":"Body_Block2.fmu", 
					"{Robot3}":"Body_Block3.fmu", 
					"{Robot4}":"Body_Block4.fmu",
					"{Controller}":"UController.fmu",
					"{Environment}":"Environment.fmu"}};
	
	var obj = JSON.stringify(text);
	var fs = require('fs');
	fs.writeFile("mm.json", obj);
				//"connections":{
					//"{Robot1}.Robot1Instance.robot_x":["{Controller}.ControllerInstance1.x",
					//"{Environment}.EnvironmentInstance.x_1"],
					//"{Robot1}.Robot1Instance.robot_y":["{Controller}.ControllerInstance1.y","{Environment}.EnvironmentInstance.y_1"],
					//"{Robot1}.Robot1Instance.robot_theta":["{Controller}.ControllerInstance1.phi"],
					//"{Controller}.ControllerInstance1.servoLeft":["{Robot1}.Robot1Instance.servo_left_input"],
					//"{Controller}.ControllerInstance1.servoRight":["{Robot1}.Robot1Instance.servo_right_input"],
					//"{Controller}.ControllerInstance1.onDestinationOutput":["{Environment}.EnvironmentInstance.onDestination1Input"],
					//"{Environment}.EnvironmentInstance.onDestinationOutput":["{Controller}.ControllerInstance1.onDestinationInput","{Controller}.ControllerInstance2.onDestinationInput","{Controller}.ControllerInstance3.onDestinationInput","{Controller}.ControllerInstance4.onDestinationInput"],
					//"{Environment}.EnvironmentInstance.xDesired1":["{Controller}.ControllerInstance1.xDesired"],
					//"{Environment}.EnvironmentInstance.yDesired1":["{Controller}.ControllerInstance1.yDesired"],
					//"{Environment}.EnvironmentInstance.xDesired2":["{Controller}.ControllerInstance2.xDesired"],
					//"{Environment}.EnvironmentInstance.yDesired2":["{Controller}.ControllerInstance2.yDesired"],
					//"{Environment}.EnvironmentInstance.xDesired3":["{Controller}.ControllerInstance3.xDesired"],
					//"{Environment}.EnvironmentInstance.yDesired3":["{Controller}.ControllerInstance3.yDesired"],
					//"{Environment}.EnvironmentInstance.xDesired4":["{Controller}.ControllerInstance4.xDesired"],
					//"{Environment}.EnvironmentInstance.yDesired4":["{Controller}.ControllerInstance4.yDesired"],
					//"{Controller}.ControllerInstance2.servoLeft":["{Robot2}.Robot2Instance.servo_left_input"],
					//"{Controller}.ControllerInstance2.servoRight":["{Robot2}.Robot2Instance.servo_right_input"],
					//"{Controller}.ControllerInstance2.onDestinationOutput":["{Environment}.EnvironmentInstance.onDestination2Input"],
					//"{Controller}.ControllerInstance3.servoLeft":["{Robot3}.Robot3Instance.servo_left_input"],
					//"{Controller}.ControllerInstance3.servoRight":["{Robot3}.Robot3Instance.servo_right_input"],
					//"{Controller}.ControllerInstance3.onDestinationOutput":["{Environment}.EnvironmentInstance.onDestination3Input"],
					//"{Controller}.ControllerInstance4.onDestinationOutput":["{Environment}.EnvironmentInstance.onDestination4Input"],
					//"{Controller}.ControllerInstance4.servoLeft":["{Robot4}.Robot4Instance.servo_left_input"],
					//"{Controller}.ControllerInstance4.servoRight":["{Robot4}.Robot4Instance.servo_right_input"],
					//"{Robot2}.Robot2Instance.robot_x":["{Controller}.ControllerInstance2.x","{Environment}.EnvironmentInstance.x_2"],
					//"{Robot2}.Robot2Instance.robot_y":["{Controller}.ControllerInstance2.y","{Environment}.EnvironmentInstance.y_2"],
					//"{Robot2}.Robot2Instance.robot_theta":["{Controller}.ControllerInstance2.phi"],
					//"{Robot3}.Robot3Instance.robot_x":["{Controller}.ControllerInstance3.x","{Environment}.EnvironmentInstance.x_3"],
					//"{Robot3}.Robot3Instance.robot_y":["{Controller}.ControllerInstance3.y","{Environment}.EnvironmentInstance.y_3"],
					//"{Robot3}.Robot3Instance.robot_theta":["{Controller}.ControllerInstance3.phi"],
					//"{Robot4}.Robot4Instance.robot_x":["{Environment}.EnvironmentInstance.x_4","{Controller}.ControllerInstance4.x"],
					//"{Robot4}.Robot4Instance.robot_y":["{Environment}.EnvironmentInstance.y_4","{Controller}.ControllerInstance4.y"],
					//"{Robot4}.Robot4Instance.robot_theta":["{Controller}.ControllerInstance4.phi"]
				//},
				//"parameters":{
					//"{Robot1}.Robot1Instance.initial_position[0]":0.5,
					//"{Robot1}.Robot1Instance.initial_position[1]":0.5,
					//"{Robot1}.Robot1Instance.initial_position[2]":0,
					//"{Robot1}.Robot1Instance.battery_initial_energy":1e+21,
					//"{Robot2}.Robot2Instance.initial_position[0]":9.5,
					//"{Robot2}.Robot2Instance.initial_position[1]":0.5,
					//"{Robot2}.Robot2Instance.initial_position[2]":0,
					//"{Robot2}.Robot2Instance.battery_initial_energy":1e+21,
					//"{Robot3}.Robot3Instance.initial_position[0]":9.5,
					//"{Robot3}.Robot3Instance.initial_position[1]":9.5,
					//"{Robot3}.Robot3Instance.initial_position[2]":0,
					//"{Robot3}.Robot3Instance.battery_initial_energy":1e+21,
					//"{Robot4}.Robot4Instance.initial_position[0]":0.5,
					//"{Robot4}.Robot4Instance.initial_position[1]":9.5,
					//"{Robot4}.Robot4Instance.initial_position[2]":0,
					//"{Robot4}.Robot4Instance.battery_initial_energy":1e+21
					//"{Environment}.EnvironmentInstance.mapSize":12,
					//"{Environment}.EnvironmentInstance.nObstacles":8,
					//"{Environment}.EnvironmentInstance.nRobots":4,
					//"{Environment}.EnvironmentInstance.lx_1":0.5,
					//"{Environment}.EnvironmentInstance.lx_2":9.5,
					//"{Environment}.EnvironmentInstance.lx_3":9.5,
					//"{Environment}.EnvironmentInstance.ly_1":0.5,
					//"{Environment}.EnvironmentInstance.ly_2":0.5,
					//"{Environment}.EnvironmentInstance.ly_3":9.5,
					//"{Environment}.EnvironmentInstance.lx_4":0.5,
					//"{Environment}.EnvironmentInstance.ly_4":9.5,
				//}
			//}';
}
