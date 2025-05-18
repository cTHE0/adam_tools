#ifndef SHA256_H
#define SHA256_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialise le tableau H avec les constantes initiales SHA-256.
 */
void sha256_init(uint32_t H[8]);

/**
 * Traite un bloc de 64 octets (512 bits) et met à jour le tableau H.
 * @param block Un bloc de 64 octets.
 * @param H État interne SHA-256 à 8 mots de 32 bits.
 */
void sha256_process_block(const uint8_t block[64], uint32_t H[8]);

/**
 * Calcule le hash SHA-256 d’un fichier donné.
 * @param filename Chemin du fichier.
 * @param hash Tableau de 32 octets où sera écrit le hash final.
 */
void sha256_file(const char* filename, uint8_t hash[32]);

#ifdef __cplusplus
}
#endif

#endif // SHA256_H
