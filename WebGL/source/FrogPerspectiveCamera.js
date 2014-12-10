function FrogPerspectiveCamera(){
	this.fov = 70.0;
	this.aspectRatio = gl.viewportWidth / gl.viewportHeight;
	this.near = 0.1;
	this.far = 30.1;

	this.pos = [1.0 , 1.0, 0.5];
	this.up = [0.0, 0.0, 1.0];
	this.at = [0.0, 2.0, 0.0];
}

FrogPerspectiveCamera.prototype.load = function() {
	mat4.perspective(pMatrix, this.fov, this.aspectRatio, this.near, this.far);
	mat4.lookAt(mvMatrix, this.pos, this.at, this.up);
}

FrogPerspectiveCamera.prototype.update = function() {
	this.pos = [game.frog.position[0], game.frog.position[1]-2.0, game.frog.position[2]+2.0];
	this.at = [game.frog.position[0], game.frog.position[1]+3.0, game.frog.position[2]];
}