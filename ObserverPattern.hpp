/*******************************************************************************
*
*   ObserverPattern.hpp
*
*   Joel Goodman, joelrgoodman@gmail.com
*	
*   --DESCRIPTION--
*   Publisher and Subscriber classes that enable use of the observer design
*		pattern.
*
*******************************************************************************/
#ifndef OBSERVERPATTERN_HPP
#define OBSERVERPATTERN_HPP

/** @file ObserverPattern.hpp
*   \brief Classes that facilitatates use of the observer pattern.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>


class Subscriber{
protected:
	std::string name_;
public:
	virtual void getMessage(std::string);
	std::string name();

	/* Overloads for the == operator. These become important when removing
	   Subscribers from the Publisher's list
   */
	const bool operator == (Subscriber &other);
	const bool operator == (std::string str);
	const bool operator != (Subscriber &other);
	const bool operator != (std::string str);

	/* TODO: Perhaps this is better accomplished with an enum? */
	Subscriber(std::string name);
};


class Publisher{
protected:
	std::vector<std::shared_ptr<Subscriber>> subscribers_;
	std::string name_;
	void publish();
	/* message_ is the string that gets published by publish(). May not be
	   completely necessary in the long run. This could be passed directly,
	   which might yield better/faster results.
	*/
	std::string message_;

public:
	std::string name();

	/* The user can remove subscribers from the list with this function by
	   either passing a pointer to the subscriber in question or the name
	   of the subscriber, probably using the output of name(). Passing the
	   pointer is probably the best/safest way to do this, but for now the
	   option to do both exists.*/
	void removeSubscriber(std::string name);
	void removeSubscriber(std::shared_ptr<Subscriber> subscriber);
	void addSubscriber(std::shared_ptr<Subscriber> new_subscriber);

	/* TODO: Perhaps this is better accomplished with an enum? */
	Publisher(std::string name);
};

#endif /* OBSERVERPATTERN_HPP */