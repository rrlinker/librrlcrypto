#include <rrlinker/crypto/evp_context.hpp>

#include <openssl/evp.h>

using namespace rrl;
using namespace rrl::rlc;

EVPContext::EVPContext()
    : context(EVP_CIPHER_CTX_new())
{}

EVPContext::~EVPContext() {
    if (context != nullptr) {
        EVP_CIPHER_CTX_free(context);
        context = nullptr;
    }
}

