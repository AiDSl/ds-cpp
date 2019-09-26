#include <iostream>
#include <stdexcept>


class myIO
{
	using self_type=myIO;
	public:
		self_type& self;
		std::istream& input;
		std::ostream& output;
		myIO():input(std::cin),output(std::cout),self(*this)
		{};	
		
		
		self_type& operator() ()
		{
			
			self.input.clear();
			self.input.sync();
			
			self.output<<"\nPress Enter key to continue..."<<std::endl;
			self.input.ignore();
			
			return self;
		};
		template<class T>
		self_type& operator<< (const T& data)
		{
			self.output<<data;
			return self;
		};
		template<class T>
		self_type& operator>> (T& data)
		{
			self.input>>data;
			return self;
		};
} cio;

class signal
{};
	class signal_alone:public signal
	{};
	class signal_terminal:public signal
	{};
	class signal_entrance:public signal
	{};
	class signal_tree:public signal
	{};

template <class T>
class node
{
	using entity=node<T>;
	using pointer=entity*;
	using self_type=node<T>;
	
	public:
		T data;
		pointer next;
		pointer side;
		pointer root;
		
		
		//the way below is good way to initialize your data		
		node(signal_alone						,T input):data(input),next(nullptr)	,root(nullptr)	,side(nullptr)
		{};
		node(signal_terminal	,pointer from	,T input):data(input),next(nullptr)	,root(from)		,side(nullptr)
		{};
		node(signal_entrance	,pointer from	,T input):data(input),next(from)		,root(nullptr)	,side(nullptr)
		{};
		node(signal_tree		,pointer from	,T input):data(input),next(nullptr)	,root(from)		,side(nullptr)
		{};

		
};



template <class T>
class holder
{
	using entity=node<T>;
	using pointer=entity*;
	using self_type=holder<T>;
	
	public:
		self_type& self;
		pointer thing;
		
		holder():self(*this),thing(nullptr)
		{};
		holder(const self_type& from):self(*this),thing(new entity(signal_alone(),from.thing->data))
		{};
		~holder()
		{
			if(not self.isEmpty()) this->take();
		};
		
		
		
		bool isEmpty()
		{
			return this->thing==nullptr;
		}
		void checkOnly()
		{
			if(this->thing==this->thing) return;
			return;
		}
		
		
		self_type& operator= (self_type& from)
		{
			if(not self.isEmpty()) this->take();
			if(from.isEmpty()) return self;
			this->thing=new entity(signal_alone(),from.thing->data);
			return self;
			
		};
		T& give(T& input)
		{
			if(self.isEmpty()) 
				this->thing=new entity(signal_alone(),input);
			else 
				throw std::out_of_range("holder overflow");
				
			return input;
		};
		const T& give(const T& input)
		{
			if(self.isEmpty()) 
				this->thing=new entity(signal_alone(),input);
			else 
				throw std::out_of_range("holder overflow");
			return input;
		};
		T take()
		{
			if(self.isEmpty()) throw std::out_of_range("holder underflow");
			
			
			T output(this->thing->data);
			delete this->thing;
			this->thing=nullptr;
			return output;
		};
		
		T operator() ()
		{return T(thing->data);};
		
		friend std::ostream& operator<< (std::ostream& output,const self_type& that)
		{
			return output<<&that;
		};
};




int main()
{
	using h1=holder<const char*>;
	using h2=holder<h1>;
	h1 string;
	h2 hs;
	
	/*cio<<new node<h1>(signal_alone(),string);*/
	/*hs.give(string);
	(cio<<hs)();*/
	
	
	
	
	
	(cio<<string.give("What??"))();
	h1 str(string);
	(cio<<h1(string).take())();
	(cio<<string.take())();
	(cio<<str.take())();
	(cio<<string)();
	
	
	
	return 0;
} 
