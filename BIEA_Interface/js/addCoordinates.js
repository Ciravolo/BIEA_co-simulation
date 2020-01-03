function addCoordinates(number, container){
	// Clear previous contents of the container
	while (container.hasChildNodes()) {
		container.removeChild(container.lastChild);
	}
	for (i=0;i<number;i++){
		// Append a node with a random text
		container.appendChild(document.createTextNode("X" + (i+1) + ":"));
		// Create an <input> element, set its type and name attributes
		var input = document.createElement("input");
		input.style = "width:50%;";
		input.type = "number";
		input.class = "form-control";
		input.name = container.id + "x" + (i+1);
		input.id = container.id + "x" + (i+1);
		container.appendChild(input);
		container.appendChild(document.createElement("br"));
		container.appendChild(document.createElement("br"));
		var spanX = document.createElement("span");
		spanX.id = container.id + "x" + (i+1) + "_error_msg";
		spanX.style = "color:red";
		container.appendChild(spanX);
		container.appendChild(document.createElement("br"));
		container.appendChild(document.createTextNode("Y" + (i+1) + ":"));
		var input2 = document.createElement("input");
		input2.style = "width:50%;";
		input2.type = "number";
		input2.class = "form-control";
		input2.name = container.id + "y" + (i+1);
		input2.id = container.id + "y" + (i+1);
		container.appendChild(input2);
		container.appendChild(document.createElement("br"));
		var spanY = document.createElement("span");
		spanY.id = container.id + "y" + (i+1) + "_error_msg";
		spanY.style = "color:red";
		container.appendChild(spanY);
		container.appendChild(document.createElement("br"));
		// Append a line break 
		if(i != (number - 1)) {
			container.appendChild(document.createElement("br"));
			container.appendChild(document.createElement("br"));
			container.appendChild(document.createElement("br"));
			container.appendChild(document.createElement("br"));
		}
		else {
			container.appendChild(document.createElement("br"));
			container.appendChild(document.createElement("br"));
		}
	}
}
