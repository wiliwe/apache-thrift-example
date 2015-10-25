import java.net.InetSocketAddress;

import org.apache.thrift.server.*;
import org.apache.thrift.server.TThreadPoolServer;
import org.apache.thrift.transport.*;

import IDV.*;

public class PersonServer{
	private static final int PORT = 8989;
	
	public static void main(String[] args) {
		try {
			TServerTransport serverTransport = new TServerSocket( new InetSocketAddress("127.0.0.1", PORT));
			PersonService.Processor processor = new PersonService.Processor(new PersonServiceImpl());
   		    TServer server = new TThreadPoolServer(new TThreadPoolServer.Args(serverTransport).processor(processor));

   		    System.out.println("Thrift service start...");
   		    server.serve();
   		    
   		    server.stop();
   		    System.out.println("Thrift service stop...");
		} 
		catch(Exception e){
            // System.out.println("Server could not start...");
			e.printStackTrace();
			
			System.out.println("\n\n\n");
			
			throw new RuntimeException("thrift service fail..." + "\n" + e.getMessage());
        }
	}
}
