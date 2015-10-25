////////////////////////////////////////////////
/* The client to retrieve Person object data. */
////////////////////////////////////////////////

#include <iostream>
#include <string>

#if 1
#include <thrift/protocol/TBinaryProtocol.h>
#else
#include <thrift/protocol/TJSONProtocol.h>
#endif
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/TLogging.h>

#include "PersonService.h"

#define T_GLOBAL_DEBUGGING_LEVEL 1   // please refer to <thrift/TLogging.h>

#define SERVER_ADDR "localhost"
#define LISTEN_PORT 8989  /*9090*/
#define EMPLOYEE_ID 125

using namespace IDV;
using namespace std;
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

using boost::shared_ptr;

int main(int argc, char **argv)
{
  shared_ptr<TTransport> socket(new TSocket(SERVER_ADDR, LISTEN_PORT));
  shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  #if 1
  shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  #else
  shared_ptr<TProtocol> protocol(new TJSONProtocol(transport));
  #endif
  PersonServiceClient client(protocol);

  try {
      try {
        transport->open();
      } catch(TTransportException& tx) {
        T_ERROR("when trying to open socket, cause : %s", tx.what());
        std::cout << "when trying to open socket, cause : " << tx.what() << std::endl;
      }

      try {
        Person objPerson;

        client.getPersonById(objPerson, EMPLOYEE_ID);

        T_DEBUG("ID     Name     Age   Marriage");
        T_DEBUG("%d   %s   %d      %d", objPerson.id, objPerson.name.c_str(), objPerson.age, objPerson.married);

        std::cout << "ID     Name     Age   Marriage" << std::endl;
        std::cout << objPerson.id << "    " << objPerson.name.c_str() << "     " << objPerson.age << "       " << objPerson.married << std::endl;
      } catch (TException& tx) {
        T_ERROR("when calling getPersonById(), cause : %s", tx.what());
        std::cout << "when calling getPersonById(), cause :" << tx.what() << std::endl;
      }

      try {
        client.deletePersonById(EMPLOYEE_ID);
      } catch (TException& tx) {
        T_ERROR("when calling deletePersonById(), cause : %s", tx.what());
        std::cout << "when calling deletePersonById(), cause :" << tx.what() << std::endl;
      }

      transport->close();

  } catch (TException& tx) {
      T_ERROR("cause : %s", tx.what());
      std::cout << "cause :" << tx.what() << std::endl;
  }

  return 0;
}

