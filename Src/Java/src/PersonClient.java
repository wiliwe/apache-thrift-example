import java.lang.System;

import org.apache.thrift.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.transport.*;

import IDV.*;

public class PersonClient {
    private static final int PORT = 8989;

    public static void main(String[] args) throws TException {
       TTransport transport = new TSocket("127.0.0.1", PORT);
       TProtocol protocol = new TBinaryProtocol(transport);
       PersonService.Client client = new PersonService.Client(protocol);
       long start = 0;
       
       transport.open();

       System.out.println("開始呼叫...");
       start = System.currentTimeMillis();   // store/remember start time
       Person person = client.getPersonById(125);

       System.out.println("呼叫结果：" + person.toString());
       transport.close();

       System.out.println("消耗時間：" + (System.currentTimeMillis()-start) + "ms");  // calculate the elapsed time.
    }
}
