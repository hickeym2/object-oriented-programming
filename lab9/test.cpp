class SuperClass
{
    public:

        SuperClass(int foo)
        {
            // do something with foo
        }
};

class SubClass : public SuperClass
{
    public:

        SubClass(int foo, int bar)
        : SuperClass(fopo)    // Call the superclass constructor in the subclass' initialization list.
        {
            // do something with bar
        }
};

int main(){

}
