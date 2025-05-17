#!/bin/bash

# CONFIGURATION
VERSION="1.0"
PACKAGE_NAME="adam-tools"
BINARY_NAME="adam_tools"
ARCH="amd64"

# Préparation des dossiers
BUILD_DIR="build"
DEB_DIR="$BUILD_DIR/$PACKAGE_NAME"
BIN_DIR="$DEB_DIR/usr/local/bin"
CONTROL_DIR="$DEB_DIR/DEBIAN"
OUTPUT_DEB="${BINARY_NAME}_${VERSION}_${ARCH}.deb"

# Nettoyage
rm -rf "$BUILD_DIR"
mkdir -p "$BIN_DIR" "$CONTROL_DIR"

# Compilation
echo "[+] Compilation de $BINARY_NAME.c"
make || { echo "Erreur de compilation"; exit 1; }

# Copie du binaire
cp "$BINARY_NAME" "$BIN_DIR/"

# Fichier de contrôle
cat > "$CONTROL_DIR/control" <<EOF
Package: $PACKAGE_NAME
Version: $VERSION
Section: utils
Priority: optional
Architecture: $ARCH
Maintainer: Ton Nom <ton.email@example.com>
Description: Adam Tools - une collection d’outils système personnalisés.
EOF

# Construction du .deb
echo "[+] Création du paquet .deb"
dpkg-deb --build "$DEB_DIR" > /dev/null

# Renommage
mv "$DEB_DIR.deb" "$OUTPUT_DEB"
echo "[✓] Paquet généré : $OUTPUT_DEB"
