#include "Customers/Customer.h"

//static members initialization
unsigned int Customer::M_ID_COUNTER = 0;
const std::string Customer::M_ID_PREFIX= "#ID#";

Customer::Customer()
	:	m_id(Utils::GenerateNumberedStringWithPrefix(M_ID_PREFIX, M_ID_COUNTER)),
		m_name(),
		m_address()
{
	M_ID_COUNTER++;
}

Customer::Customer(const std::string& name, const std::string& address)
	:	m_id(Utils::GenerateNumberedStringWithPrefix(M_ID_PREFIX, M_ID_COUNTER)),
		m_name(name),
		m_address(address)
{
	M_ID_COUNTER++;
}

void Customer::SetID(const std::string & id)
{
	m_id = id;
}

void Customer::SetName(const std::string & name)
{
	m_name = name;
}

void Customer::SetAddress(const std::string & address)
{
	m_address = address;
}

const std::string Customer::GetID() const
{
	return std::string(m_id);
}

const std::string Customer::GetName() const
{
	return std::string(m_name);
}

const std::string Customer::GetAddress() const
{
	return std::string(m_address);
}


void Customer::DisplayCustomerInfo() const
{
	std::cout << (*this);
}

bool Customer::Equals(Customer& other)
{
	return m_id == other.m_id;
}

// friend methods
std::ostream& operator<<(std::ostream& outStream, const Customer& customer)
{
	outStream << "customer name : " << customer.m_name 
		<< "\ncustomer ID : " << customer.m_id 
		<< "\naddress : " << customer.m_address << '\n';

	return outStream;
}

std::istream& operator>>(std::istream& inStream, Customer& customer)
{
	std::string name;
	std::string address;

	std::cout << "enter customer name : ";
	std::getline(std::cin, name);

	std::cout << "enter customer address : ";
	std::getline(std::cin, address);

	customer.SetName(name);
	customer.SetAddress(address);

	return inStream;
}