/*******************************************************************************
*
*   ObserverPattern.cpp
*  
*   Joel Goodman, joelrgoodman@gmail.com
*	
*   --DESCRIPTION--
*   Publisher and Subscriber classes that enable use of the observer design
*		pattern.
*
*******************************************************************************/

#include "ObserverPattern.hpp"

/*	~~~~~ SUBSCRIBER ~~~~~	*/
Subscriber::Subscriber(std::string name) : name_(name){}
Subscriber::~Subscriber(){}

void Subscriber::getMessage(std::string){}
std::string Subscriber::name(){ return name_ ; }

const bool Subscriber::operator == (Subscriber &other)
{
	return name_ == other.name();
}
const bool Subscriber::operator == (std::string str)
{
	return name_ == str;
}
const bool Subscriber::operator != (Subscriber &other)
{
	return !(*this == other);
}
const bool Subscriber::operator != (std::string str)
{
	return !(*this == str);
}


/*	~~~~~ PUBLISHER ~~~~~	*/
Publisher::Publisher(std::string name) : name_(name){}
Publisher::~Publisher(){}

std::string Publisher::name(){ return name_ ; }

void Publisher::addSubscriber(std::shared_ptr<Subscriber> new_subscriber)
{
	subscribers_.push_back(new_subscriber);
}
void Publisher::removeSubscriber(std::string name)
{
	subscribers_.erase(
		std::remove_if(subscribers_.begin(), subscribers_.end(), 
			[&](std::shared_ptr<Subscriber> i){ return *i == name;}),
					   subscribers_.end());
}
void Publisher::removeSubscriber(std::shared_ptr<Subscriber> subscriber)
{
	subscribers_.erase(
		std::remove(subscribers_.begin(), subscribers_.end(), subscriber),
		subscribers_.end()); 
}

void Publisher::publish()
{
	for(auto i : subscribers_){
		i->getMessage(message_);
	}
}

