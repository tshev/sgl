
class mlp_shape {

};

template<typename T, typename A>
class mlp {
public:
    typedef A activation_type;
    typedef T value_type;

private:
    value_type* data;
    size_t input_size;
    size_t output_size;
public:
    mlp(T* data, mlp_shape shape, A activation) : data(data) 
};
/*


size_t sizes[] = {300, 300, 128};

sgl::nn::linear<float, sgl::v1::selu<float>> s0(data, s[0], s[1]);
sgl::nn::linear<float, sgl::v1::selu<float>> s1(data, s[1], x[2]);
sgl::nn::linear<float, sgl::v1::selu<float>> s2(data, s[2], x[3]);

sgl::nn::sequential mlp(data, s0, s1, s2);

class neural_net {
    

};
*/

template<typename T>
class dssm {
    T* data;
    
    size_t n; 

    
};
