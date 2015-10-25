// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "PersonService.h"

#include <iostream>
#include <string>

//#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/TLogging.h>

#define LISTEN_PORT 8989  /*9090*/
#define EMPLOYEE_ID 125

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::IDV;

class PersonServiceHandler : virtual public PersonServiceIf {
 public:
  PersonServiceHandler() {
    // Your initialization goes here
  }

  void getPersonById(Person& _return, const int32_t id) {
    // Your implementation goes here

    T_DEBUG_T();

    std::cout << __FUNCTION__ << "(" << id << ")" << std::endl;

    if(id == EMPLOYEE_ID)
    {
      _return.id = id;
      _return.name = "John";
      _return.age = 99;
      _return.married = false;
    }
    else
    {
       _return.id = 0;
       _return.name = "";
       _return.age = 0;
       _return.married = false;
    }
  }

  bool deletePersonById(const int32_t id) {
    // Your implementation goes here
    if(id == EMPLOYEE_ID)
    {   // remember to add braces around "T_DEBUG_T" macro!
      T_DEBUG_T("deletePersonById");
    }
    else
    {   // remember to add braces around "T_DEBUG_T" macro!
      T_DEBUG_T("Specified employee ( %d ) could not be found!", id);
    }

    // If this line is missing, it will cause to show this error message:
    // < the terminate called after throwing an instance of 'apache::thrift::protocol::TProtocolException*' >
    return false;
  }

};

int main(int argc, char **argv) {
  int port = LISTEN_PORT;   // listen port
  shared_ptr<PersonServiceHandler> handler(new PersonServiceHandler());
  shared_ptr<TProcessor> processor(new PersonServiceProcessor(handler));
  //
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  #if 1
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
  #else
  shared_ptr<TProtocolFactory> protocolFactory(new TJSONProtocolFactory());
  #endif

  std::cout << "Thrift server starting..." << std::endl;

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();

  return 0;
}

