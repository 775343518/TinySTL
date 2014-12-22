#include "VectorTest.h"

namespace TinySTL{
	namespace VectorTest{

		void testCase1(){
			stdVec<std::string> v1(10, "zxh");
			tsVec<std::string> v2(10, "zxh");
			assert(TinySTL::Test::container_equal(v1, v2));

			stdVec<std::string> v3(10);
			tsVec<std::string> v4(10);
			assert(TinySTL::Test::container_equal(v3, v4));

			std::array<std::string, 3> arr = { "abc", "def", "ghi" };
			stdVec<std::string> v5(std::begin(arr), std::end(arr));
			tsVec<std::string> v6(std::begin(arr), std::end(arr));
			assert(TinySTL::Test::container_equal(v5, v6));
		}
		void testCase2(){
			stdVec<int> temp1(10, 0);
			tsVec<int> temp2(10, 0);

			auto v1(temp1);
			auto v2(temp2);
			assert(TinySTL::Test::container_equal(v1, v2));

			auto v3(std::move(temp1));
			auto v4(std::move(temp2));
			assert(TinySTL::Test::container_equal(v3, v4));

			auto v5 = v1;
			auto v6 = v2;
			assert(TinySTL::Test::container_equal(v5, v6));

			auto v7 = std::move(v3);
			auto v8 = std::move(v4);
			assert(TinySTL::Test::container_equal(v7, v8));
		}
		void testCase3(){
			tsVec<int> v1, v2;
			for (int i = 0; i != 100; ++i){
				v1.push_back(i);
				v2.push_back(i);
			}

			assert(v1 == v2);
			assert(!(v1 != v2));
		}
		void testCase4(){
			tsVec<int> myvector;
			for (int i = 1; i <= 5; i++) myvector.push_back(i);

			std::cout << "myvector contains:";
			for (tsVec<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			std::cout << "myvector contains:";
			for (tsVec<int>::const_iterator it = myvector.cbegin(); it != myvector.cend(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
		}
		void testCase5(){
			tsVec<int> myvector(5);  // 5 default-constructed ints
			int i = 0;
			tsVec<int>::reverse_iterator rit = myvector.rbegin();
			for (; rit != myvector.rend(); ++rit)
				*rit = ++i;

			std::cout << "myvector contains:";
			for (tsVec<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
			std::cout << "myvector contains(reverse order):";
			for (tsVec<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
		}
	}
}

using namespace TinySTL::VectorTest;
int main(){
	//testCase1();
	//testCase2();
	//testCase3();
	//testCase4();
	//testCase5();
	system("pause");
	return 0;
}