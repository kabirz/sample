package com.example.kabir;

import android.os.IBinder;
import android.os.Parcel;
import android.os.RemoteException;
import android.os.ServiceManager;
import android.util.Log;

public class Sample {
    private static final String TAG = "Sample.Kabir";
    private static final int   NUM_ADD = 0;
    private static final int   NUM_ADD2 = 1;

    public static void main(String[] argv) {
        int value = 0;
        Log.i(TAG, "Client oncreate");
        Parcel data = Parcel.obtain();
        Parcel reply = Parcel.obtain();
        IBinder b = ServiceManager.getService("demo.Kabir");
        try {
            data.writeInterfaceToken("demo.IKabir");
            data.writeInt(300);
            data.writeInt(900);
            b.transact(NUM_ADD2, data, reply, 0);
            value = reply.readInt();
        } catch (RemoteException e) {
            e.printStackTrace();

        } finally {
            reply.recycle();
            data.recycle();
        }

        System.err.println("value is " + value);
    }
}
