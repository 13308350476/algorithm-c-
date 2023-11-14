#include"iostream"
#include <vector>
#include<stack>
#include<queue>
#include <unordered_map>
#include <memory>
#include <string>
#include <mutex>
#include "temp1.hpp"
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TEST{
    public:
        TEST() {
            shared_ptr<int> temp(new int);
            ptr = temp;
            cout << "GOU ZAO HAN SHU:" << ptr.use_count() << endl;
        }
        ~TEST() {
            cout << "XI GOU HAN SHU" << endl;
        }
        int get_value() {
            return value;
        }
        void set_value(int a) {
            value = a;
        }
    public:
        int value = 8;
        shared_ptr<int> ptr;
};

void test(){
    TEST* ptr = new TEST();
    shared_ptr<TEST> mytest1(ptr);
    cout << mytest1.use_count() << endl;
    shared_ptr<TEST> mytest2(mytest1);
    cout << mytest2.use_count() << endl;
}
void print(char* ptr) {
    // ptr = "sssss";
    cout << ptr << endl;
}

template<typename T>

T add(T A,T B) {
    return A+B;
}

template<typename T>
T SUB(T A,T B) {
    return A-B;
}

void func(){
    TEST test1;
    cout << "test1 count is:" << test1.ptr.use_count() << endl;
    TEST test2 = test1;
    cout << "test2 count is:" << test1.ptr.use_count() << endl;
}


int main() {
    // test();
    // char* ptr;
    // ptr[0] = 'i';
    // print(ptr);
    // float ptr = add<int>(1,2.5);
    // cout << ptr << endl;
    fun(1);
    return 0;
}





///  加锁的懒汉式实现  //

class SingleInstance
{

public:
    // 获取单实例对象
    static SingleInstance *GetInstance();

    //释放单实例，进程退出时调用
    static void deleteInstance();
	
    // 打印实例地址
    void Print();

private:
    // 将其构造和析构成为私有的, 禁止外部构造和析构
    SingleInstance();
    ~SingleInstance();

    // 将其拷贝构造和赋值构造成为私有函数, 禁止外部拷贝和赋值
    SingleInstance(const SingleInstance &);
    const SingleInstance &operator=(const SingleInstance &);

private:
    // 唯一单实例对象指针
    static SingleInstance *m_SingleInstance;
    static std::mutex m_Mutex;
};


//初始化静态成员变量
SingleInstance *SingleInstance::m_SingleInstance = nullptr;
std::mutex SingleInstance::m_Mutex;

// 注意：不能返回指针的引用，否则存在外部被修改的风险！
SingleInstance * SingleInstance::GetInstance()
{

    //  这里使用了两个 if 判断语句的技术称为双检锁；好处是，只有判断指针为空的时候才加锁，
    //  避免每次调用 GetInstance的方法都加锁，锁的开销毕竟还是有点大的。
    if (m_SingleInstance == nullptr) 
    {
        std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
        if (m_SingleInstance == nullptr)
        {
            m_SingleInstance = new (std::nothrow) SingleInstance();
        }
    }

    return m_SingleInstance;
}

void SingleInstance::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex); // 加锁
    if (m_SingleInstance)
    {
        delete m_SingleInstance;
        m_SingleInstance = nullptr;
    }
}

void SingleInstance::Print()
{
	std::cout << "我的实例内存地址是:" << this << std::endl;
}

SingleInstance::SingleInstance()
{
    std::cout << "构造函数" << std::endl;
}

SingleInstance::~SingleInstance()
{
    std::cout << "析构函数" << std::endl;
}

void fun1(int a) {cout << a <<endl;}
void fun2(int a) {cout << a <<endl;}
void fun3(int a) {cout << a <<endl;}
void fun4(int a) {cout << a <<endl;}
void fun5(int a) {cout << a <<endl;}
using F = void (*)(int a);
F functions[5] = {
    fun1,fun2,fun3,fun4,fun5
};


// int main() {
//     for(int i = 0;i<5;i++) {
//         functions[i](i);
//     }
// }