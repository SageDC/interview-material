// Thread synchronized Java implementation of singleton design pattern
class Singleton {
    private static Singleton obj;

    private Singleton() {}

    // Only one thread can execute at a time
    // Con: Using synchronized every time while creating the singleton object is expensive and may decrease performance
    // If getInstance is not critical than this method is a clean and simple solution
    public static synchronized Singleton getInstance() {
        if(obj == null)
            obj = new Singleton();
        return obj;
    }
}