public class Simple {
    public native void print();

    static{
	System.loadLibrary("Simple");
    }

    public static void main(String[] args){
	new Simple().print();
    }
}
