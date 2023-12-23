import numpy as np
import matplotlib.pyplot as plt

def load_idx_file(file_path):
    with open(file_path, 'rb') as f:
        # Lire l'en-tête
        magic_number = int.from_bytes(f.read(4), byteorder='big')
        num_items = int.from_bytes(f.read(4), byteorder='big')
        num_rows = int.from_bytes(f.read(4), byteorder='big')
        num_cols = int.from_bytes(f.read(4), byteorder='big')

        # Lire les données
        data = np.frombuffer(f.read(), dtype=np.uint8)

    # Remodeler les données pour les images
    data = data.reshape(num_items, num_rows, num_cols)

    return data

def show_image(image):
    plt.imshow(image, cmap='gray')
    plt.show()

# Charger le fichier IDX
file_path = '../data/t10k-images.idx3-ubyte'
images = load_idx_file(file_path)

# Afficher une image (par exemple, la première)
show_image(images[0])
print(f" { len(images) = } \n {len(images[0]) =}")
