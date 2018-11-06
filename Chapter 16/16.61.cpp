#include <memory>

using namespace std;

template<typename T, typename... Args>
auto Make_shared(Args&&...args)->shared_ptr<T>
{
	return shared_ptr<T>(new T(std::forward(args)...));
}