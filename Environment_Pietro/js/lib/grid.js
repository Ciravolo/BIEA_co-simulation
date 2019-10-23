// Box width
var bw = 300;
// Box height
var bh = 300;

			var canvas = document.getElementById("canvas");
			var context = canvas.getContext('2d');
			function drawBoard(){
				context.fill();
				context.beginPath();
				for (var x = 0; x <= bw; x += 30) {
					context.moveTo(x, 0);
					context.lineTo(x, bh);
				}

				for (var x = 0; x <= bh; x += 30) {
					context.moveTo(0, x);
					context.lineTo(bw, x);
				}
				context.strokeStyle = "black";
				context.lineWidth = 1.5;
				context.stroke();
			}
			drawBoard();
