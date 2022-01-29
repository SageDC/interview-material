// Double Checked Locking (DSL) based Java implementation of singleton design pattern
// Volatile ensures that multiple threads offer the obj variable corectly when it is being initialized to Singleton instance
// This method drastically reduces the overhead of calling the synchronized method every time
class Singleton {
    private static volatile Singleton obj = null;

    private Singleton() {}

    public static Singleton getInstance() {
        if(obj == null) {
            // to make thread safe
            synchronized (Singleton.class) {
                if(obj == null)
                    obj = new Singleton();
            }
        }
        return obj;
    }
}