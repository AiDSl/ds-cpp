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
