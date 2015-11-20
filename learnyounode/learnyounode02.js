var x = 0;
for(i=2; i<process.argv.length; i++){
	x += +process.argv[i];
}
console.log(x);