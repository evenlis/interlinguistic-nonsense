public class Simple {
    public native void print();
    public native void print_arg(int a);
    public native int sum_array(int[] a);

    static{
	System.loadLibrary("Simple");
    }

    public static void main(String[] args){
	Simple s = new Simple();
	s.print();
	s.print_arg(5);
	int[] a = {1,2,3,4,5};
	System.out.printf("Array sum calculated by c code: %d\n", s.sum_array(new int[]{1,2,3,4,5,6}));
    }
}
