# Couleurs pour l'affichage
GREEN='\033[0;32m'
BGREEN='\033[1;92m'
RED='\033[0;31m'
BRED='\033[1;91m'
ICyan='\033[1;96m'
NC='\033[0m' # No Color

# Répertoire contenant les fichiers à vérifier
REP_TO_CHECK="."

# Commande pour exécuter la norminette (ajustez-la selon votre environnement)
NORMINETTE_CMD="norminette -R CheckForbidenSourceHeader"

# Variable pour suivre les erreurs
ERRORS_FOUND=0

echo "\n${ICyan}${NORMINETTE_CMD}${NC} :\n"
# Parcours de tous les fichiers .c et .h de manière récursive
for file in $(find $REP_TO_CHECK -type f \( -name "*.c" -o -name "*.h" \)); do
    # Exécution de la norminette
    result=$($NORMINETTE_CMD $file 2>&1)

    # Vérification du résultat
    if [ $? -eq 0 ]; then
        echo "${GREEN}Norminette OK: $file${NC}"
    else
        echo "${RED}Norminette KO: $file${NC}"
        echo "$result"
        ERRORS_FOUND=$((ERRORS_FOUND + 1))
    fi
done
# Vérification finale
if [ $ERRORS_FOUND -eq 0 ]; then
    echo "\n${BGREEN}Diff OK!${NC}\n"
else
    echo "\n${BRED}Diff KO!${NC}\n"
fi

# Commande pour exécuter la norminette (ajustez-la selon votre environnement)
NORMINETTE_CMD="norminette -R CheckDefine"

echo "${ICyan}${NORMINETTE_CMD}${NC} :\n"
# Parcours de tous les fichiers .c et .h de manière récursive
for file in $(find $REP_TO_CHECK -type f \( -name "*.c" -o -name "*.h" \)); do
    # Exécution de la norminette
    result=$($NORMINETTE_CMD $file 2>&1)

    # Vérification du résultat
    if [ $? -eq 0 ]; then
        echo "${GREEN}Norminette OK: $file${NC}"
    else
        echo "${RED}Norminette KO: $file${NC}"
        echo "$result"
        ERRORS_FOUND=$((ERRORS_FOUND + 1))
    fi
done
# Vérification finale
if [ $ERRORS_FOUND -eq 0 ]; then
    echo "\n${BGREEN}Diff OK!${NC}\n"
else
    echo "\n${BRED}Diff KO!${NC}\n"
fi

