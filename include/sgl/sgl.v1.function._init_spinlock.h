namespace sgl {
namespace v1 {

template<typename T, typename U, typename Ostream, typename S>
void _init_spinlock(T* state_, U* count_, Ostream& cerr, S& shared_mutex_) {
        auto count = count_->fetch_add(1u);
        if (count == 0u) {
            if (state_->load() == 1ul) {
                cerr << "Waiting for destruction\n";
                while (state_->load() == 1ul); // wait for destructuction before the recreation
            }
            sgl::v1::construct(shared_mutex_);
            state_->store(1ul);
        } else {
            if (state_->load() == 0) {
                cerr << "Waiting for construction\n";
                while (state_->load() == 0);  // can't the object use before it was initialized
            }
        }
}

}
}
