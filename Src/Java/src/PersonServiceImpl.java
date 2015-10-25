import org.apache.thrift.TException;

import IDV.*;

public class PersonServiceImpl implements PersonService.Iface {
	Person p = null;
	
	@Override
	public Person getPersonById(int id) throws TException{
		p = new Person(id, "William", 99, false);
		
		return p;
	}
	
	@Override
	public boolean deletePersonById(int id) throws TException{
		return false;
	}
}
