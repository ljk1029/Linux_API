for file in *; do
    if [ -f "$file" ]; then
        mv "$file" "socket_$file"
    fi
done
