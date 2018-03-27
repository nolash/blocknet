//******************************************************************************
//******************************************************************************

#ifndef XBRIDGECRYPTOPROVIDERSEQ_H
#define XBRIDGECRYPTOPROVIDERSEQ_H

#include "secp256k1.h"
#include "uint256.h"

#include <vector>

//******************************************************************************
//******************************************************************************
namespace xbridge
{

//******************************************************************************
//******************************************************************************
class SeqCryptoProvider
{
public:
    SeqCryptoProvider();
    ~SeqCryptoProvider();

public:
    bool check(const std::vector<unsigned char> & key);
    void makeNewKey(std::vector<unsigned char> & key);
    bool getPubKey(const std::vector<unsigned char> & key, std::vector<unsigned char> & pub);

    bool sign(const std::vector<unsigned char> & key,
              const uint256 & data,
              std::vector<unsigned char> & signature);
    bool verify(const std::vector<unsigned char> & pubkey,
                const uint256 & data,
                const std::vector<unsigned char> & signature);

private:
    secp256k1_context * context;
};

} // namespace xbridge

#endif // XBRIDGECRYPTOPROVIDERSEQ_H
