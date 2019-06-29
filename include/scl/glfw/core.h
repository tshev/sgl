#pragma once
#include <future>
#include <cstring>
#include <memory>
#include <functional>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace scl {
namespace glfw {
namespace v1 {
constexpr auto gl_color_buffer_bit = GL_COLOR_BUFFER_BIT;

struct window;
struct full_screen_tag {};

inline
void activate(window& x);

inline
GLFWwindow* create_window(int width, int height, const char* title);

inline
GLFWwindow* create_window(int width, int height, const char* title, full_screen_tag);


struct window {
public:
    typedef GLFWwindow window_type;
    typedef window_type* pointer;
//private:
    GLFWwindow* window_;
    int width_;
    int height_;
public:
    window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share, bool activate = true) :
      window_(glfwCreateWindow(width, height, title, monitor, share)), width_(width), height_(height) {
      validate();
      if (activate) {
        glfwMakeContextCurrent(window_);
      }
    }

    window(int width, int height, const char* title, GLFWmonitor* monitor, bool activate = true) : 
      window(width, height, title, monitor, NULL, activate) {}

    window(int width, int height, const char* title, bool activate = true) : 
      window(width, height, title, NULL, NULL, activate) {}

    window(int width, int height, const char* title, full_screen_tag x, bool activate = true) :
      window(width, height, title, glfwGetPrimaryMonitor(), NULL, activate) {}
    
    void validate() const {
        if (window_ == nullptr) {
            ::glfwTerminate();
            throw std::runtime_error("window is NULL. You could forget to call `glfwInit()`");
        }
    }
    
    pointer data() {
      return window_;
    }

    ~window() {
        glfwDestroyWindow(window_);
    }
    
    void set_window_user_pointer(void* ctx) {
      return glfwSetWindowUserPointer(window_, ctx);
    }

    GLFWcharfun set_char_callback(GLFWcharfun cbfun) {
      return glfwSetCharCallback(window_, cbfun);
    }

    std::pair<int, int> frame_buffer_size() const {
    	std::pair<int, int> width_height;
			glfwGetFramebufferSize(window_, &width_height.first, &width_height.second);
			return width_height;
		}

    void activate() {
      scl::glfw::v1::activate(*this);
    }
};

inline
GLFWwindow* create_window(int width, int height, const char* title) {
  return glfwCreateWindow(width, height, title, NULL, NULL);
}

inline
GLFWwindow* create_window(int width, int height, const char* title, full_screen_tag) {
  return glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), NULL);
}

template<typename T, size_t offset>
void on_scroll_bind(GLFWwindow* pw, double dx, double dy) {
  //window* wptr = reinterpret_cast<window*>(pw);
  //T* functor = reinterpret_cast<T*>(reinterpret_cast<char>(pw) + offset);
  //functor->operator()(*wptr, dx, dy);
}

template<typename T, size_t offset>
void on_char_bind(GLFWwindow* pw, unsigned int x) {
  //window* wptr = reinterpret_cast<window*>(pw);
  //T* functor = reinterpret_cast<T*>(reinterpret_cast<char>(pw) + offset);
  //functor->operator()(*wptr, x);
}

void assign(uint8_t* x, uint64_t y) {
  
}

uint64_t ptrg;

template<typename OnScroll, typename OnChar>
struct window_io {
  typedef OnScroll on_scroll_type;
  typedef OnChar on_char_type;

  uint8_t raw_data[sizeof(void*) + 10 * sizeof(void*)];
  window* window_ptr;
  on_scroll_type on_scroll;

  int x = 320;
  std::function<void(GLFWwindow*, unsigned int)> on_char;
  window_io(window& window_ref) : window_ptr(&window_ref) { register_callbacks(); }

  window_io(window& window_ref, on_scroll_type on_scroll, on_char_type on_char) : window_ptr(&window_ref), on_scroll(on_scroll), on_char(on_char) {
    /***************************************** Register callbacks ****************************************************/
    register_callbacks();
  }

  void register_callbacks() {
    glfwSetCharCallback(window_ptr->window_, [](GLFWwindow *win, unsigned int codepoint){
    });
  }
};

inline
void make_context_current(window &win) {
  glfwMakeContextCurrent(win.data());
}

inline
void activate(window& x) {
    glfwMakeContextCurrent(x.data());
}

inline
bool window_should_close(window& x) {
    return glfwWindowShouldClose(x.data());
}

inline
void swap_buffers(window& x) {
    glfwSwapBuffers(x.data());
}

inline
void poll_events() {
    glfwPollEvents();
}

inline
void gl_clear(int color) {
    return glClear(color);
}

template<typename W>
struct ioloop {
    W* window;
    ioloop(W& window) : window(&window) {}

		template<typename F>
    void operator()(F func) {
        while (!window_should_close(*window)) {
            /* Render here */
						func(*window);

            /* Swap front and back buffers */
            swap_buffers(*window);

            /* Poll for and process events */
            poll_events();
        }
    }
};
inline
float ratiof(const std::pair<int, int> x) {
  return float(x.first) / float(x.second);
}
inline
double ratiod(const std::pair<int, int> x) {
  return double(x.first) / double(x.second);
}


} // namespace v1
} // namespace glfw
} // namespace scl
