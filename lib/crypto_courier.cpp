#include <rrlinker/crypto/crypto_courier.hpp>

using namespace rrl;
using namespace rrl::rlc;

CryptoCourier::CryptoCourier(Connection &conn)
    : conn_(conn)
{}

CryptoCourier::~CryptoCourier() noexcept(false) {}

msg::Any CryptoCourier::receive() {
    conn_.gather_and_decrypt();
    msg::Any msg;
    msg.read(conn_);
    conn_.ensure_recv_buffer_empty();
    return msg;
}

void CryptoCourier::send(msg::Any const &msg) {
    msg.write(conn_);
    conn_.encrypt_and_flush();
}

void CryptoCourier::init_as_client(RSA const &rsa) {
    conn_.init_as_client(rsa);
}

void CryptoCourier::init_as_server(RSA const &rsa) {
    conn_.init_as_server(rsa);
}

void CryptoCourier::init_with_key(Bytes const &key) {
    conn_.init_with_key(key);
}
