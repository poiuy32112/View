# View Engine - 高性能跨平台2D游戏引擎

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-Windows%20x64-lightgrey.svg)]()
[![Build System](https://img.shields.io/badge/Build-Premake5-orange.svg)]()

**View** 是一款专为2D游戏开发而设计的高性能、模块化、跨平台的游戏引擎。基于C++17从底层构建，通过优化的2D渲染管线、完整的游戏开发工具链和现代ECS架构，为2D游戏开发提供完整的解决方案。

> 该项目最初从包括TheCherno引擎开发系列在内的教育资源中汲取灵感，但已发展为具有自定义架构决策和优化的独立实现。

---

## 开始使用

推荐使用 Visual Studio 2019 或 2022，本项目主要在 Windows 环境下开发和测试。

**1. 下载仓库：**

使用以下命令克隆仓库（包含子模块）：
```bash
git clone --recursive https://github.com/poiuy32112/View.git
```

如果之前已经克隆但没有包含子模块，请使用：
```bash
git submodule update --init
```

**2. 配置依赖项：**

运行位于 `View` 文件夹中的 `GenerateProjects.bat` 文件。这将自动
完成项目文件配置并生成 Visual Studio 解决方案文件。

---
## 🎯 核心特性

### 引擎核心架构
- **事件驱动设计**：基于观察者模式的解耦通信系统
- **实体组件系统**：由EnTT驱动的灵活ECS架构
- **分层应用框架**：组织化代码结构的模块化层系统
- **内存管理**：智能指针抽象和自定义分配器
- **跨平台抽象**：平台无关API，支持Windows实现

### 渲染管线
- **现代OpenGL后端**：支持多后端的抽象渲染API
- **批量渲染系统**：优化的绘制调用批处理，实现最高性能
- **着色器管理**：动态着色器编译和缓存系统
- **相机系统**：正交和透视相机实现
- **纹理管线**：高效的纹理加载和管理

### 开发工具
- **Viewnut编辑器**：具有实时预览的全功能场景编辑器
- **ImGui集成**：专业的调试和开发UI
- **资产管理**：全面的资源加载和缓存
- **场景序列化**：基于YAML的场景持久化系统
- **可视化Gizmo**：通过ImGuizmo实现的交互式变换工具

---

## 🏗️ 架构与设计模式

### 核心设计原则

#### 1. **RAII和智能内存管理**
```cpp
// 清晰所有权语义的自定义智能指针别名
template<typename T>
using Scope = std::unique_ptr<T>;  // 独占所有权

template<typename T>
using Ref = std::shared_ptr<T>;    // 共享所有权

// 一致对象创建的工厂函数
template<typename T, typename... Args>
constexpr Scope<T> CreateScope(Args&&... args);
```

#### 2. **基于模板的组件系统**
```cpp
template<typename T, typename... Args>
T& AddComponent(Args&&... args)
{
    VI_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");
    T& component = m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
    m_Scene->OnComponentAdded<T>(*this, component);
    return component;
}
```

#### 3. **静态多态性和类型安全**
- 广泛使用模板实现零成本抽象
- 编译时类型检查和优化
- SFINAE条件模板实例化

### 设计模式实现

#### **单例模式** (应用程序核心)
- 应用程序实例管理的线程安全单例
- 受控的全局访问和适当的生命周期管理

#### **观察者模式** (事件系统)
- 类型安全的事件分发系统
- 解耦的组件通信
- 事件过滤和优先级处理

#### **策略模式** (渲染后端)
- 可插拔的渲染API实现
- 运行时渲染器选择和切换
- 接口与实现的清晰分离

#### **工厂模式** (资源管理)
- 具有适当初始化的集中对象创建
- 资源池化和重用策略
- 参数转发的类型安全工厂方法

---

## 📏 代码风格规范

### 命名约定
```cpp
// 类名：PascalCase
class RenderCommand { };

// 成员变量：m_ 前缀 + camelCase  
private:
    std::unique_ptr<Window> m_Window;
    bool m_Running = true;

// 静态成员：s_ 前缀
private:
    static Application* s_Instance;

// 函数：公有用PascalCase，私有用camelCase
public:
    void OnEvent(Event& e);
private:
    bool onWindowClose(WindowCloseEvent& e);

// 常量：全大写加下划线
#define VI_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
```

### 最佳实践

#### **头文件组织**
```cpp
#pragma once

// 系统包含
#include <memory>
#include <string>

// 第三方包含
#include <glm/glm.hpp>

// 项目包含
#include "Core.h"
#include "View/Events/Event.h"
```

#### **资源管理**
- 始终使用RAII进行资源获取
- 尽可能优先使用栈分配
- 动态分配使用智能指针
- 实现适当的移动语义以提升性能

#### **错误处理**
```cpp
// 用于开发调试的断言宏
#ifdef VI_ENABLE_ASSERTS
#define VI_CORE_ASSERT(x, ...) { if(!(x)) { VI_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#endif

// 通过RAII确保异常安全
// 发布版本中的优雅降级
```

---

## 🛠️ 构建系统与项目结构

### Premake5配置
- 多配置支持 (Debug/Release/Dist)
- 通过子模块进行依赖管理
- PCH (预编译头文件) 以加快编译速度
- UTF-8编码支持，确保跨平台兼容性

### 项目层次结构
```
View/
├── View/              # 核心引擎库
│   ├── src/
│   │   ├── View/      # 引擎模块
│   │   │   ├── Core/           # 应用程序框架
│   │   │   ├── Renderer/       # 渲染子系统
│   │   │   ├── Scene/          # ECS和场景管理
│   │   │   ├── Events/         # 事件系统
│   │   │   └── ImGui/          # UI集成
│   │   └── Platform/   # 平台特定实现
│   └── vendor/         # 第三方依赖
├── Viewnut/           # 场景编辑器应用程序
├── Sandbox/            # 开发测试环境
└── scripts/            # 构建和配置工具
```

---

## 🧪 测试与开发

**Sandbox** 项目作为主要的测试环境，具有以下功能：
- 渲染系统验证
- 性能分析和基准测试
- 功能原型设计和实验
- 新组件的集成测试

---

## 📋 开发路线图

### 当前版本 (v0.1)
- [x] 核心应用程序框架
- [x] 事件系统实现
- [x] 基础2D渲染器
- [x] ImGui集成
- [x] 场景编辑器基础

### 即将推出的功能
- [ ] 音频系统集成
- [ ] 高级光照和阴影
- [ ] 脚本支持
- [ ] 资产管线改进
- [ ] 多平台支持 (Linux/macOS)

---

## 🤝 贡献

本项目遵循现代C++开发实践，欢迎维护代码质量和架构一致性的贡献。请确保所有提交都包含适当的测试和文档。
