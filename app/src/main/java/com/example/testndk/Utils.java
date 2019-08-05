package com.example.testndk;

/**
 * File description.
 *
 * @author sufeng
 * @date 2019-08-05
 */
public class Utils {

    static {
        System.loadLibrary("native-lib");
    }

    public static native void write(String password);

    public static native String read();

}
