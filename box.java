class box {
	double length;
	double width;
	double height;
	
	double volume(){
		return length*width*height;
	}
}
class demobox {
	public static void main(String args[]){
		box mybox1 = new box();
		box mybox2 = new box();
		double vol;
		mybox1.length = 10;
		mybox1.width = 10;
		mybox1.height = 10;
		
		mybox2.length = 14;
		mybox2.width = 45;
		mybox2.height = 12;
		
		vol = mybox2.volume();
		system.out.println("volume is" + vol);
		vol = mybox1.volume();
		system.out.println("volume is" + vol);
	}
}
		
	
	