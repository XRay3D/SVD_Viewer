#!/bin/bash
# generate_code.sh
XSD_FILE=$1
OUTPUT_DIR="generated"

# Создаем директорию для результатов
mkdir -p $OUTPUT_DIR

# Генерируем код
xsdcxx cxx-tree \
    --output-dir $OUTPUT_DIR \
    --namespace-map "http://yournamespace/=YourNamespace" \
    --hxx-suffix .hpp \
    --cxx-suffix .cpp \
    --generate-serialization \
    $XSD_FILE

echo "Код сгенерирован в директорию: $OUTPUT_DIR"
