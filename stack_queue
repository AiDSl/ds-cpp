#include <iostream>
#include <string>
#include <stdexcept>
//just a attempt

#ifndef nullptr
#define nullptr 0
#endif



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
class element
{
	using entity=element<T>;
	using pointer=entity*;
	using self_type=element<T>;
	
	public:
		T data;
		pointer next;
		pointer side;
		pointer root;
		
		
		//the way below is good way to initialize your data	
		element(signal_alone							):            next(nullptr)	,root(nullptr)	,side(nullptr)
		{};		
		element(signal_alone					,T input):data(input),next(nullptr)	,root(nullptr)	,side(nullptr)
		{};
		element(signal_terminal	,pointer from	,T input):data(input),next(nullptr)	,root(from)		,side(nullptr)
		{};
		element(signal_entrance	,pointer from	,T input):data(input),next(from)		,root(nullptr)	,side(nullptr)
		{};
		element(signal_tree		,pointer from	,T input):data(input),next(nullptr)	,root(from)		,side(nullptr)
		{};

		self_type& operator= (T that)
		{
			this->data=that;
			return *this;
		}
		self_type& operator= (self_type& that)
		{
			this->data=that->data;
			this->next=that->next;
			this->side=that->side;
			this->root=that->root;
			return *this;
		}
};

template <class T>
class stack
{
	using entity=element<T>;
	using pointer=entity*;
	using self_type=stack<T>;
	
	
	public:
		pointer begin;
		pointer& ent;
		pointer& ext;
		pointer end;
		
		stack():begin(nullptr),end(nullptr),ent(end),ext(end)
		{};
		stack(self_type& from):begin(nullptr),end(nullptr),ent(end),ext(end)
		{*this+=from;};
		~stack()
		{this->clear();};
		
		void clear()
		{
			pointer hodler=new entity(signal_alone());
			std::cout<<"\n\tErasing "<<this<<" Stack"<<"\n";
			while(this->begin!=nullptr)
			{
				*hodler=(this->pop());
				std::cout<<"\tPop\t-\t"<<hodler->data<<"\n";
			}
			std::cout<<"\tStack "<<this<<" Clear!"<<"\n\n";
		};
		
		T& operator() ()
		{return this->ext->data;};
		
		self_type& operator+= (self_type& from)
		{
			pointer there(from.begin);
			pointer here(this->end);
			if(there==nullptr) return *this;
			if(here==nullptr)
			{
				this->begin=new entity(signal_alone(),there->data);
				this->end=this->begin;
				here=this->begin;
				there=there->next;
			}
			
			while(there!=nullptr)
			{
				here->next=new entity(signal_terminal(),here,there->data);
				here=here->next;
				there=there->next;
			}
			
			
			this->end=here;
			return *this;
		}
		
		self_type& operator= (self_type& from)
		{
			this->clear();
			*this+=from;
			return *this;
		}
		
		T push(T input)
		{
			if(this->begin==nullptr)
			{
				this->begin=new entity(signal_alone(),input);
				this->ent=this->begin;
				this->end=this->ent;
			}
			else
			{
				this->ent->next=new entity(signal_terminal(),this->ent,input);
				this->ent=this->ent->next;
			}
			return input;
		};
		
		T pop()
		{
			if(this->ext==nullptr) throw std::out_of_range("stack underflow");
			T output=this->ext->data;
			
			{	//this part is for delete element	
				pointer perv=this->ext->root;
				delete this->ext;
				if(this->begin==this->ext) this->begin=perv;	//when lose last element;
				this->ext=perv;
				if(this->ext!=nullptr)	this->ext->next=nullptr;
			}
			
			return output;
		};
		
		friend std::ostream& operator<< (std::ostream& output,self_type& that)
		{
			output<<&that;
			return output;
		};

};



template <class T>
class queue
{
	using entity=element<T>;
	using pointer=entity*;
	using self_type=queue<T>;
	
	
	public:
		self_type& self;
		pointer begin;
		pointer& ent;
		pointer& ext;
		pointer end;
		
		queue():begin(nullptr),end(nullptr),ent(begin),ext(end),self(*this)
		{std::cout<<"\n\t\t\tI am new queue "<<this<<"\n";};
		queue(self_type& from):begin(nullptr),end(nullptr),ent(begin),ext(end),self(*this)
		{*this+=from;std::cout<<"\n\t\t\tI am new queue "<<this<<"\n";};
		~queue()
		{
			this->clear();
		}
		
		void clear()
		{
			std::cout<<"\n\tErasing "<<this<<" Queue"<<"\n";
			while(this->begin!=nullptr)	std::cout<<"\tDequeue\t-\t"<<this->dequeue()<<"\n";
			std::cout<<"\tQueue "<<this<<" Clear!"<<"\n\n";
		}
		
		T& operator() ()
		{return this->ext->data;};
		
		self_type& operator+= (self_type& from)
		{
			pointer there(from.begin);
			pointer here(this->end);
			if(there==nullptr) return *this;
			if(here==nullptr)
			{
				this->begin=new element<T>(signal_alone(),there->data);
				this->end=this->begin;
				here=this->begin;
				there=there->next;
			}
			
			while(there!=nullptr)
			{
				here->next=new element<T>(signal_terminal(),here,there->data);
				here=here->next;
				there=there->next;
			}
			
			
			this->end=here;
			return *this;
		}
		
		self_type& operator= (self_type& from)
		{
			this->clear();
			*this+=from;
			return *this;
		}
		
		
		T enqueue(T input)
		{
			if(this->begin==nullptr)
			{
				this->begin=new entity(signal_alone(),input);
				this->ent=this->begin;
				this->end=this->ent;
			}
			else
			{
				this->ent->root=new entity(signal_entrance(),this->ent,input);
				this->ent=this->ent->root;
			}
			return input;
		};
		T dequeue()
		{
			if(this->ext==nullptr) throw std::out_of_range("queue underflow");
			T output=this->ext->data;
			
			{	//this part is for delete element
				pointer perv=this->ext->root;
				delete this->ext;
				if(this->begin==this->ext) this->begin=perv;//when lose last element;
				this->ext=perv;
				if(this->ext!=nullptr) this->ext->next=nullptr;
			}
			
			return output;
		};
};

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
		self_type& operator <<(const T& data)
		{
			self.output<<data;
			return self;
		};
		template<class T>
		self_type& operator >>(T& data)
		{
			self.input>>data;
			return self;
		};
} cio;

int main()
{	
	{
		using entity=stack<int>;
		
		entity x;
		for(int i=0;i<10;i++)	cio<<"Push\t+\t"<<x.push(i)<<"\n";
		for(int i=0;i<1;i++)	cio<<"\tPop\t-\t"<<x.pop()<<"\n";
		entity z(x);
		for(int i=0;i<3;i++)	cio<<"Push\t+\t"<<x.push(i)<<"\n";
		for(int i=0;i<1;i++)	cio<<"\tPop\t-\t"<<x.pop()<<"\n";
		for(int i=0;i<3;i++)	cio<<"Push\t+\t"<<x.push(i)<<"\n";
		for(int i=0;i<4;i++)	cio<<"\tPop\t-\t"<<x.pop()<<"\n";
		
		entity y(x);
	}cio();
	{
		using entity=queue<const char*>;
		
		entity x;
		for(int i=0;i<10;i++)	cio<<"Enqueue\t+\t"<<x.enqueue("Hello")<<"\n";
		entity y(x);
		for(int i=0;i<5;i++)	cio<<"\tDequeue\t-\t"<<y.dequeue()<<"\n";
		for(int i=0;i<3;i++)	cio<<"Enqueue\t+\t"<<x.enqueue("Horay")<<"\n";
		for(int i=0;i<1;i++)	cio<<"\tDequeue\t-\t"<<x.dequeue()<<"\n";
		for(int i=0;i<3;i++)	cio<<"Enqueue\t+\t"<<x.enqueue("Hoping")<<"\n";
		for(int i=0;i<6;i++)	cio<<"\tDequeue\t-\t"<<x.dequeue()<<"\n";
	}cio();
	/*{
		using ele=stack<int>;
		using entity=stack<ele>;
		
		ele a;
		entity x;
		
		
	}cio();*/
}
