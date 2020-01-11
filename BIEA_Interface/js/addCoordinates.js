function addCoordinates(number, container){
	// Clear previous contents of the container
	while (container.hasChildNodes()) {
		container.removeChild(container.lastChild);
	}
	for (i=0;i<number;i++){
		// Append a node with a random text
		var bold1 = document.createElement("strong");
		bold1.appendChild(document.createTextNode("X" + (i+1) + ":"));
		container.appendChild(bold1);
		// Create an <input> element, set its type and name attributes
		var input = document.createElement("input");
		input.style = "display:block;width:50%;height:34px;padding:6px 12px;font-size:14px;line-height:1.42857143;color:#555;background-color:#fff;background-image:none;border:1px solid #ccc;border-radius:4px;-webkit-box-shadow:inset 0 1px 1px rgba(0,0,0,.075);box-shadow:inset 0 1px 1px rgba(0,0,0,.075);-webkit-transition:border-color ease-in-out .15s,-webkit-box-shadow ease-in-out .15s;-o-transition:border-color ease-in-out .15s,box-shadow ease-in-out .15s;transition:border-color ease-in-out .15s,box-shadow ease-in-out .15s";
		input.addEventListener("focus", function () {
			this.style.borderColor = "#66afe9";  
			this.style.outline = "0";
			this.style.boxShadow = "inset 0 1px 1px rgba(0,0,0,.075),0 0 8px rgba(102,175,233,.6)";
		});
		input.addEventListener("blur", function () {
			this.style = "display:block;width:50%;height:34px;padding:6px 12px;font-size:14px;line-height:1.42857143;color:#555;background-color:#fff;background-image:none;border:1px solid #ccc;border-radius:4px;-webkit-box-shadow:inset 0 1px 1px rgba(0,0,0,.075);box-shadow:inset 0 1px 1px rgba(0,0,0,.075);-webkit-transition:border-color ease-in-out .15s,-webkit-box-shadow ease-in-out .15s;-o-transition:border-color ease-in-out .15s,box-shadow ease-in-out .15s;transition:border-color ease-in-out .15s,box-shadow ease-in-out .15s";
;
		});
		input.type = "number";
		input.min = "0";
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
		var bold2 = document.createElement("strong");
		bold2.appendChild(document.createTextNode("Y" + (i+1) + ":"));
		container.appendChild(bold2);
		var input2 = document.createElement("input");
		input2.style = "display:block;width:50%;height:34px;padding:6px 12px;font-size:14px;line-height:1.42857143;color:#555;background-color:#fff;background-image:none;border:1px solid #ccc;border-radius:4px;-webkit-box-shadow:inset 0 1px 1px rgba(0,0,0,.075);box-shadow:inset 0 1px 1px rgba(0,0,0,.075);-webkit-transition:border-color ease-in-out .15s,-webkit-box-shadow ease-in-out .15s;-o-transition:border-color ease-in-out .15s,box-shadow ease-in-out .15s;transition:border-color ease-in-out .15s,box-shadow ease-in-out .15s";
		input2.addEventListener("focus", function () {
			this.style.borderColor = "#66afe9"; 
			this.style.outline = "0"; 
			this.style.boxShadow = "inset 0 1px 1px rgba(0,0,0,.075),0 0 8px rgba(102,175,233,.6)";
		});
		input2.addEventListener("blur", function () {
			this.style = "display:block;width:50%;height:34px;padding:6px 12px;font-size:14px;line-height:1.42857143;color:#555;background-color:#fff;background-image:none;border:1px solid #ccc;border-radius:4px;-webkit-box-shadow:inset 0 1px 1px rgba(0,0,0,.075);box-shadow:inset 0 1px 1px rgba(0,0,0,.075);-webkit-transition:border-color ease-in-out .15s,-webkit-box-shadow ease-in-out .15s;-o-transition:border-color ease-in-out .15s,box-shadow ease-in-out .15s;transition:border-color ease-in-out .15s,box-shadow ease-in-out .15s";
		});
		input2.type = "number";
		input2.min = "1";
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
