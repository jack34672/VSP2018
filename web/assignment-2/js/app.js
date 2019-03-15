// When DOM is loaded, execute the given callback function
document.addEventListener('DOMContentLoaded', function(event){

	// Hard-coded image src urls
	var imageUrls = [
		'images/image1.jpg',
		'images/image2.jpg',
		'images/image3.jpg',
		'images/image4.jpg',
		'images/image5.jpg',
		'images/image6.jpg',
		'images/image7.jpg',
		'images/image8.jpg'
	];

	var replaceGrid = function(size){
		// 1. Log to browser console
		console.log(size);

		// 2. Generate new grid and replace table
		var mainBody = document.getElementById('mainBody');				// Get mainBody element
		
		var existingGrid = document.getElementById('#imagesGrid');		// If there is an existing imagesGrid, remove it
		
		if (existingGrid) mainBody.removeChild(existingGrid);
		
		var imagesGrid = PhotoGalleryLib.generateGrid(imageUrls, size);	//  Generate new imagesGrid
		
		mainBody.appendChild(imagesGrid);								//  then add it to mainBody
	};

	// Supply the function to be called when size changes
	PhotoGalleryLib.onSizeClassChange(replaceGrid);

});