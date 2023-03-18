
#include <iostream>
using namespace std;

class Box {
    
   private:
      double length;  
	  double breadth;
	  double height;
   public:
      double getVolume(void) {
         return length * breadth * height;
      }
      void setLength( double len ) {
         length = len;
      }
      void setBreadth( double bre ) {
         breadth = bre;
      }
      void setHeight( double hei ) {
         height = hei;
      }
      void display() //I added a display function
      {
      	cout<<length<<"\t"<<breadth<<"\t"<<height<<endl;
	  }
      
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         box.height = this->height + b.height;
         return box;}
    // Overload - operator to subtract two Box objects.
    Box operator-(const Box& b) {
         Box box0;
         box0.length = this->length - b.length;
         box0.breadth = this->breadth - b.breadth;
         box0.height = this->height - b.height;
         return box0;
      }
      //postfix notation overloading
    Box operator++(int)
    {
    	Box b;
    	b=*this;
    	height++;
    	breadth++;
    	length++;
    	return b;
	}
	//prefix notation overloading
	Box operator++()
    {
    	height++;
    	breadth++;
    	length++;
    	return *this;
	}
};

int main() {
   Box Box1;                
   Box Box2;                
   Box Box3;                
   Box Box4;
   double volume = 0.0;     
 
   
   Box1.setLength(6.0);
   Box1.setBreadth(7.0);
   Box1.setHeight(5.0);
 
   
   Box2.setLength(12.0);
   Box2.setBreadth(13.0);
   Box2.setHeight(10.0);
 
   
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;

   
   Box3 = Box1 + Box2;
	
   
   volume = Box3.getVolume();
   cout << "Volume of Box3 after adding Box1 and Box2:" << volume <<endl;
   //subtracting the two objects
   Box4=Box2-Box1;
   volume=Box4.getVolume();
   cout << "Volume of Box4 after subtracting Box1 from Box2 : " << volume <<endl;
   ++Box1; //prefix overloading on Box2
	Box1.display(); 
	Box k;
	//postfix overloading on Box1
	k=Box1++; //I added k to show the effect of the postfix increment:value of Box1 are first stored inside k then incremented
	k.display();//shows Box1 with the prefix increment before the postfix
	Box1.display();//shows Box1 after being incremented using postfix
	
   return 0;
}
