import os
import numpy as np
import matplotlib.pyplot as plt
from skimage.metrics import structural_similarity as ssim

def compare_mri_images(img1_path, img2_path):
    """
    Compare two MRI images and return the structural similarity index.
    
    Args:
        img1_path (str): Path to the first MRI image.
        img2_path (str): Path to the second MRI image.
        
    Returns:
        float: Structural similarity index between the two images.
    """
    # Load the MRI images
    img1 = plt.imread(img1_path)
    img2 = plt.imread(img2_path)
    
    # Convert the images to grayscale if needed
    if len(img1.shape) > 2:
        img1 = np.mean(img1, axis=-1)
    if len(img2.shape) > 2:
        img2 = np.mean(img2, axis=-1)
    
    # Compute the structural similarity index
    similarity = ssim(img1, img2)
    
    return similarity

# # Example usage
# img1_path = 'path/to/first/mri/image.nii.gz'
# img2_path = 'path/to/second/mri/image.nii.gz'

# similarity = compare_mri_images(img1_path, img2_path)
# print(f'Structural similarity index: {similarity:.2f}')
