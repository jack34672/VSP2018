var PhotoGalleryLib = (function() {
    var PhotoGalleryLib = {};

    var viewportSmallMin = 0;
    var viewportSmallMax = 600;
    var viewportMediumMin = 601;
    var viewportMediumMax = 800;
    var viewportLargeMin = 801;
    var viewportLargeMax = Infinity;
    
    var currentViewportSize;

    PhotoGalleryLib.onSizeClassChange = function(callback) {
        if (!callback) {
            callback = function(){};
        }

        window.onresize = function() {
            var newViewportSize = getViewportSizeName(window.innerWidth);
            if (newViewportSize != currentViewportSize) {
                currentViewportSize = newViewportSize;
                callback(currentViewportSize);
            }
        };

        currentViewportSize = getViewportSizeName(window.innerWidth);
        callback(currentViewportSize);
    };

    function getViewportSizeName(width) {
        if ((width >= viewportSmallMin) && (width <= viewportSmallMax)) {
            return 'small';
        } else if ((width >= viewportMediumMin) && (width <= viewportMediumMax)) {
            return 'medium';
        } else if ((width >= viewportLargeMin) && (width <= viewportLargeMax)) {
            return 'large';
        } else {
            console.error('Invalid viewport width.');
        }
    };

    /**
     * The 'size' argument must be one of 'small', 'medium', or 'large'
     */
    PhotoGalleryLib.generateGrid = function(imageUrls, size) {
        var largeScreenGridHtml = `
            <tr>
                <td><img></td>
                <td><img></td>
                <td><img></td>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
                <td><img></td>
                <td><img></td>
                <td><img></td>
            </tr>
        `;

        var mediumScreenGridHtml = `
            <tr>
                <td><img></td>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
                <td><img></td>
            </tr>
        `;

        var smallScreenGridHtml = `
            <tr>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
            </tr>
            <tr>
                <td><img></td>
            </tr>
        `;

        var imagesGrid = document.createElement('table');
        imagesGrid.id = 'imagesGrid';
        if (size == 'large') {
            imagesGrid.innerHTML = largeScreenGridHtml;
        } else if (size == 'medium') {
            imagesGrid.innerHTML = mediumScreenGridHtml;
        } else {
            imagesGrid.innerHTML = smallScreenGridHtml;
        }

        var imageTags = imagesGrid.getElementsByTagName('img');
        for (var i = 0; i < imageTags.length; i++) {
            imageTags[i].src = imageUrls[i];
        }

        return imagesGrid;
    };

    /**
     * Creates the presentation modal, and adds it to the body.
     */
    PhotoGalleryLib.createModal = function() {
        var modal = document.createElement('div');
        modal.id = 'presentationModal';

        modal.innerHTML = `
            <img>
            <button class="closeButton">X</span>
            <button class="previousButton">Previous</span>
            <button class="nextButton">Next</span>
        `;

        modal.style.position = "fixed";
        modal.style.top =  "0px";
        modal.style.bottom = "0px";
        modal.style.left = "0px";
        modal.style.right = "0px";
        modal.style.backgroundColor = "grey";
        modal.style.display = "none";

        var modalImg = modal.getElementsByTagName('img')[0];
        modalImg.style.position = "absolute";
        modalImg.style.top = "50%";
        modalImg.style.left = "50%";
        modalImg.style.transform = "translate(-50%, -50%)";
        modalImg.style.maxHeight = "100%";
        modalImg.style.maxWidth = "100%";

        var closeButton = modal.getElementsByClassName('closeButton')[0];
        closeButton.style.position = "fixed";
        closeButton.style.top = "0px";
        closeButton.style.right = "0px";
        closeButton.style.fontFamily = "sans-serif";
        closeButton.style.height = "40px";
        closeButton.style.width = "40px";
        closeButton.style.backgroundColor = "white";

        var previousButton = modal.getElementsByClassName('previousButton')[0];
        previousButton.style.position = "fixed";
        previousButton.style.left = "0px";
        previousButton.style.bottom = "0px";
        previousButton.style.height = "40px";

        var nextButton = modal.getElementsByClassName('nextButton')[0];
        nextButton.style.position = "fixed";
        nextButton.style.right = "0px";
        nextButton.style.bottom = "0px";
        nextButton.style.height = "40px";

        document.getElementsByTagName('body')[0].appendChild(modal);
    };

    PhotoGalleryLib.initModal = function(closeBtnCb, previousBtnCb, nextBtnCb) {
        var closeButton =
            document.querySelector('#presentationModal .closeButton');
        var previousButton =
            document.querySelector('#presentationModal .previousButton');
        var nextButton =
            document.querySelector('#presentationModal .nextButton');

        closeButton.addEventListener('click', closeBtnCb);
        previousButton.addEventListener('click', previousBtnCb);
        nextButton.addEventListener('click', nextBtnCb);
    };

    PhotoGalleryLib.closePresentationModal = function() {
        var presentationModal = document.getElementById('presentationModal');
        presentationModal.style.display = 'none';
    };

    PhotoGalleryLib.openPresentationModal = function() {
        var presentationModal = document.getElementById('presentationModal');
        presentationModal.style.display = 'block';
    };

    PhotoGalleryLib.setModalImgSrc = function(src) {
        var images = document.querySelectorAll('#imagesGrid img');
        var presentationModal = document.getElementById('presentationModal');
        presentationModal.getElementsByTagName('img')[0].src = src;
    };

    PhotoGalleryLib.addImageClickHandlers = function(callback) {
        var images = document.querySelectorAll('#imagesGrid img');
        for (var i = 0; i < images.length; i++) {
            (function() {
                var image = images[i];
                var index = i;
                image.addEventListener('click', function() {
                    callback(index);
                });
            })();
        }
    };

    return PhotoGalleryLib;
})();
var lastsize;
if((window.innerWidth>=0)&&(window.innerWidth<=600)){
		lastsize = 'small';
}else if ((window.innerWidth>=601)&&(window.innerWidth<=800)){
		lastsize = 'medium';
}else if ((window.innerWidth>=801)&&(window.innerWidth<=Infinity)){
		lastsize = 'large';
}
var table1 = PhotoGalleryLib.generateGrid(['images/image1.jpg','images/image2.jpg','images/image3.jpg','images/image4.jpg','images/image5.jpg','images/image6.jpg','images/image7.jpg','images/image8.jpg'], lastsize);
        				 	document.body.appendChild(table1);

		var en = 0;
		function myfunc() {
			var width;
			   	var width = window.innerWidth;
			   	var size;

        			if ((width >= 0)&& (width <= 600) ){
            			size = 'small';
        			} else if ((width >= 601) && (width <= 800)) {
           				 size =  'medium';
        			} else if ((width >= 801) && (width <= Infinity)) {
            			 size =  'large';
        			} else {
            				console.error('Invalid viewport width.');
        			}
        			if(en == 0){
        					en = en + 1;
        			}else{
        				if(size != lastsize){
        				  	table1.remove(table1);

        					console.log(size);
			   	 table1 =  PhotoGalleryLib.generateGrid(['images/image1.jpg','images/image2.jpg','images/image3.jpg','images/image4.jpg','images/image5.jpg','images/image6.jpg','images/image7.jpg','images/image8.jpg'], size);	

        				 	document.body.appendChild(table1);
        					en = 0;
        					lastsize = size;
        				}
        			}

        	//		document.body.removeChild(PhotoGalleryLib.generateGrid(['images/image1.jpg','images/image2.jpg','images/image3.jpg','images/image4.jpg','images/image5.jpg','images/image6.jpg','images/image7.jpg','images/image8.jpg'], 
	//size));
    			};	
       // 			document.body.appendChild(PhotoGalleryLib.generateGrid(['images/image1.jpg','images/image2.jpg','images/image3.jpg','images/image4.jpg','images/image5.jpg','images/image6.jpg','images/image7.jpg','images/image8.jpg'], 
	//myfunc()));
