#include<iostream>
#include<sstream>
#include<stack>
#include<string>
using namespace std;
bool isOperator(const string& input);
void performOp(const string& input, stack<double>& CalcStack);
int main()
{
cout<<"Welcome to the Post Fix Calculator"<<endl;
stack<double> CalcStack;
string input;
while (true){
//display prompt

cout<<">>";

//get input

cin>>input;

//check for numeric value

double num;
if(istringstream(input) >> num){

CalcStack.push(num);

}

else if(isOperator(input))
{
performOp(input,CalcStack);
}
//check for quit
else if(input == "q")
{
return 0;
}

else{
cout<<"Invalid Input"<<endl;
}

}
}

bool isOperator(const string& input)
{
string ops[]={"-","+","*","/"};
for(int i=0;i<4;i++)
{
if(input==ops[i]){
return true;
}
}
return false;
}

void performOp(const string &input, stack<double>& CalcStack)
{
double rVl,lRval,result;

int rVal=CalcStack.top();
CalcStack.pop();

int lVal=CalcStack.top();
CalcStack.pop();

if(input == "-")
{
result=rVal-lVal;
}
else if(input == "+")
{
result=rVal+lVal;
}
else if(input == "/")
{
result=rVal/lVal;
}
else
{
result=rVal*lVal;
}
cout<<result<<endl;
cout<<"The numbers of elements in the stack are"<<"  " <<CalcStack.size()<<endl;
CalcStack.push(result);
}
