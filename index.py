import tkinter as tk
from PIL import Image, ImageTk

class GroceryStoreApp:
    def __init__(self, root):
        self.root = root
        self.root.title("eGrocery_Store")

        # Increase the window size to make it larger
        self.root.geometry("1200x800")  # Adjust the dimensions to your preference

        # Create a frame for the top menu bar
        self.menu_frame = tk.Frame(root, bg="lightgray")
        self.menu_frame.pack(fill="x", side="top", anchor="e")  # Adjust the side and anchor

        # Create and configure the title label
        self.title_label = tk.Label(self.menu_frame, text="eGrocery_Store", font=("Arial", 20), bg="lightgray")
        self.title_label.pack(side="left", padx=10)  # Shift to the left side

        # Create and configure widgets for the top menu bar
        self.home_button = tk.Button(self.menu_frame, text="Signup", command=self.show_home)
        self.home_button.pack(side="right", padx=10)  # Shift to the right side

        self.profile_button = tk.Button(self.menu_frame, text="Cart", command=self.show_profile)
        self.profile_button.pack(side="right", padx=10)  # Shift to the right side

        self.login_button = tk.Button(self.menu_frame, text="Categories", command=self.show_login)
        self.login_button.pack(side="right", padx=10)  # Shift to the right side

        self.signup_button = tk.Button(self.menu_frame, text="Home ", command=self.show_signup)
        self.signup_button.pack(side="right", padx=10)  # Shift to the right side


        # Create a frame for the content
        self.content_frame = tk.Frame(root)
        self.content_frame.pack(fill="both", expand=True)

        # Create a frame for the products
        self.product_frame = tk.Frame(self.content_frame)
        self.product_frame.pack(side="top", fill="both", expand=True)  # Move to the top

        # Create and configure widgets for the product frame
        self.title_label = tk.Label(self.product_frame, text="Welcome to Our Grocery Store", font=("Arial", 18))
        self.title_label.pack(pady=20)

        # Load and display product images
        self.load_and_display_products()

        # Create a frame for the category buttons and center it
        self.category_frame = tk.Frame(self.content_frame, bg="lightgray")
        self.category_frame.pack(fill="both", expand=True)  # Center the frame

        # Create and configure widgets for the category frame
        self.side_panel_title = tk.Label(self.category_frame, text="Categories", font=("Arial", 18), bg="lightgray")
        self.side_panel_title.pack(pady=10)

        # Create a frame for the category buttons and center it
        self.category_buttons_frame = tk.Frame(self.category_frame, bg="lightgray")
        self.category_buttons_frame.pack()

        self.categories_list = ["Munchies", "Vegetables", "Dairy", "Fruits", "Beverages", "Household"]
        for category in self.categories_list:
            category_button = tk.Button(self.category_buttons_frame, text=category,font=("Arial", 18), command=lambda c=category: self.show_category(c))
            category_button.pack(side="left", padx=15, pady=10)  # Arrange horizontally at the center

    def load_and_display_products(self):
        self.product_list = [
            {"name": "Corn Flakes", "price": 1.99, "image": "image4.jpg"},
            {"name": "Chips", "price": 0.99, "image": "image5.jpg"},
            {"name": "Salt", "price": 2.49, "image": "image6.jpeg.jpg"},
            # Add more products here
        ]

        for product in self.product_list:
            product_frame = tk.Frame(self.product_frame)
            product_frame.pack(side="left", padx=10, fill="both", expand=True)

            product_name_label = tk.Label(product_frame, text=product["name"])
            product_name_label.pack()

            product_image = Image.open(product["image"])
            product_image = ImageTk.PhotoImage(product_image)
            product_image_label = tk.Label(product_frame, image=product_image)
            product_image_label.photo = product_image  # Keep a reference to the image
            product_image_label.pack()

            product_price_label = tk.Label(product_frame, text=f"Price: ${product['price']:.2f}")
            product_price_label.pack()

            add_to_cart_button = tk.Button(product_frame, text="Add to Cart")
            add_to_cart_button.pack()

    def show_category(self, category):
        # Add logic to display products for the selected category
        # You can filter and display products based on the category
        pass
    def show_home(self):
        # Add logic to display the home content
        pass
    
    def show_profile(self):
        # Add logic to display the user profile
        pass
    
    def show_login(self):
        # Add logic to display the login page
        pass
    
    def show_signup(self):
        # Add logic to display the signup page
        pass

if __name__ == "__main__":
    root = tk.Tk()
    app = GroceryStoreApp(root)
    root.mainloop()
