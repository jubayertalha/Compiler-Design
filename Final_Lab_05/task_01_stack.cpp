#include <iostream>
using namespace std;
int stack[100], n=100, top=-1;//defined a stack array of size 100 and n contains the size of the stack. top is initiazied as -1 as there are no item in the stack

void push(int val) { //push method take an integer value as item and push it to the stack in the top
   if(top>=n-1){ // as n-1 is 99 the last index of the array, if the top is greater or equal to 99 then the stack is full and cant push a item in the stack
   cout<<"Stack Overflow"<<endl;
    }
   else {
      top++; //if the stack is not overflow then we increase the value of top by 1
      stack[top]=val; // and insert the item into the stack in the new top 
   }
}

void pop() { //pop method remove the current top item
   if(top<=-1) { //if the top is less or equal to -1 then there is no item in stack to pop
   cout<<"Stack Underflow"<<endl;
   }
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--; //if the stack is not underflow then we decrease the top by 1 so the new top item will be the item before it was
   }
}

void display() { //display method prints the item of the stack
   if(top>=0) { //if the top is greater or equal to 0 then the stack has item to display otherwise the stack is empty
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--) //the for loop print stack item from the top to last item.
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty" << endl;
}
int main() { //main method to operate the stack
   int ch, val;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch; //user choose the option to push or pop or display or exit
      switch(ch) {
         case 1: { //if user choose option 1 then the program ask for a value to push into the stack
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val); //push the item into the stack
            break;
         }
         case 2: { //if user choose option 2 then the program pop the current top item of stack
            pop(); //pop the current top item of stack
            break;
         }
         case 3: { //if user choose option 3 then the program print the stack from top to last item
            display(); //display the item of the stack
            break;
         }
         case 4: { //if user choose option 4 then the program exit
            cout<<"Exit"<<endl;
            break;
         }
         default: { //if the user choose neither of the mentioned option the program take it as an invalid option as ask again
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4); //the do while loop continue untill the choose option is not 4. if 4 then the loop is terminated 
   return 0;
} //end of the program