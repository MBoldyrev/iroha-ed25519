#ifndef PROJECT_ED25519_COMMON_HPP_
#define PROJECT_ED25519_COMMON_HPP_

#include <cassert>
#include <cstddef>

namespace iroha_ed25519 {
namespace v2 {

struct MessageView {
  unsigned char const* data_;
  int length_;

  template <typename Data, typename Length>
  MessageView(Data const* data, Length length)
      : data_(reinterpret_cast<decltype(data_)>(data)),
        length_(static_cast<decltype(length_)>(length)){
    static_assert(sizeof(data_) == sizeof(data), "type mismatch");
    assert(1 << (8 * sizeof(length_) - 1) > length);
  };

  template <typename Container>
  explicit MessageView(Container const& c) : MessageView(c.data(), c.size()) {}

  unsigned char const *data() const { return data_; }
  int size() const { return length_; }
};

template<int Size>
struct FixedSizeView {
  enum {kSize = Size};
  unsigned char const* data_;

  template <typename Data>
  explicit FixedSizeView<Size>(Data const* data)
      : data_(reinterpret_cast<decltype(data_)>(data)){
    static_assert(sizeof(data_) == sizeof(data), "type mismatch");
  };

  template <typename Container>
  explicit FixedSizeView<Size>(Container const& c)
      : FixedSizeView<Size>(c.data()) {
    assert(c.size() == Size);
  }

  unsigned char const *data() const { return data_; }
  static constexpr int size() { return Size; }
};

template<int Size>
struct FixedSizeMessage {
  enum {kSize = Size};
  unsigned char *data_;

  FixedSizeMessage<Size>() : data_(buffer_) {}

  template <typename Data>
  explicit FixedSizeMessage<Size>(Data* data)
      : data_(reinterpret_cast<decltype(data_)>(data)) {
    static_assert(sizeof(data_) == sizeof(data), "type mismatch");
  };

  template <typename Container>
  explicit FixedSizeMessage<Size>(Container const& c)
      : FixedSizeMessage<Size>(c.data()) {
    assert(c.size() == Size);
  }

  unsigned char *data() const { return data_; }
  static constexpr int size() { return Size; }

 private:
  unsigned char buffer_[Size];
};

}  // namespace v2
}  // namespace iroha_ed25519

#endif  //  PROJECT_ED25519_COMMON_HPP_
