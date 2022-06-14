#ifndef CALLBACKTYPE_H
#define CALLBACKTYPE_H
#include <functional>
using namespace std;

// 回调类型
typedef std::function<void ()> VOID_CallBackEvent_VOID;

// 绑定类，回调对象
#define BindEvent(Event,pThis) std::bind(Event, pThis)

#endif // CALLBACKTYPE_H
