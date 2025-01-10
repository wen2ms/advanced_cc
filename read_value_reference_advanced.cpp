#include <iostream>
#include <cstdio>

class Animation {
  public:
    Animation() : rank_(new int(1)) {
        printf("Constructor, Rank address: %p\n", rank_);  
    }

    Animation(const Animation& other) : rank_(new int(*other.rank_)) {
        printf("Copy constructor, Rank address: %p\n", rank_);   
    }

    Animation(Animation&& other) : rank_(other.rank_) {
        other.rank_ = nullptr;

        printf("Move constructor, Rank address: %p\n", rank_);  
    }

    ~Animation() {
        delete rank_;  
        rank_ = nullptr;

        printf("Destructor\n"); 
    }

    int* rank_;
};

Animation get_animation_a() {
    Animation animation;

    printf("Rank address: %p\n", animation.rank_);

    // Exists Return Value Optimaztion(RVO)
    return animation;
}

Animation get_animation_b() {       
    return Animation();
}

int main() {
    Animation animation_a = get_animation_a();
    printf("Rank address: %p\n", animation_a.rank_);   
    
    std::cout << std::endl;

    Animation animation_b = get_animation_b();
    printf("Rank address: %p\n", animation_b.rank_);   

    std::cout << std::endl;

    Animation&& animation_c = get_animation_b();
    printf("Rank address: %p\n", animation_c.rank_);   

    return 0;
}