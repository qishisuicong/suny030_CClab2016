// hold variables 

var city = '';
var state = '';
var APIkey = '6d07c243a17360aa';
var APIKEY = 'AIzaSyCTfnGBG0kSDKaT-z5su3yS4BXxSkCXJ9c';

// insert all the data into the divs
function loadWeather(data){
	console.log(data);
	if(data.response.error){//data is the name of the data being passed(so it's the whole entire object in this case)
		alert(data.response.error.description);//to access the object inside of it, you use .
		return;
	}
	var thisCity = data.current_observation.display_location.city;//reach an array
	var temperature = data.current_observation.temp_c;
	var weather = data.current_observation.weather;
	var icon = data.current_observation.icon_url;
	$('#temperature').html(temperature);
	$('#weather').html(weather);
	$('#weatherIcon').html('<img src="'+icon+'">');
	if (thisCity == 'New York'){
		$('#currentCity').val('New York Rocks You');

	}else{
		$('#currentCity').val(thisCity);
		}

}
// get city 
// get weather data
function initMap() {
        var styledMapType = new google.maps.StyledMapType(
          [
            {
            "featureType": "landscape",
            "elementType": "geometry",
            "stylers": [
            { "hue": "#3300ff" },
            { "saturation": 33 },
            { "lightness": -9 }
          ]
            },{
            "featureType": "road",
            "stylers": [
            { "weight": 1.1 },
            { "lightness": -4 },
            { "hue": "#7f00ff" }
          ]
            },{
            "featureType": "water",
            "stylers": [
            { "hue": "#0091ff" },
            { "saturation": -39 },
            { "lightness": 70 }
          ]
            },{
            "featureType": "poi",
            "elementType": "geometry",
            "stylers": [
            { "visibility": "on" },
            { "hue": "#9000ff" }
          ]
            }
          ],
          {name: 'Styled Map'});
        var map = new google.maps.Map(document.getElementById('map'), {
          zoom: 8,
          center: {lat: 40.7128, lng: -74.0059},
          mapTypeControlOptions: {
            mapTypeIds: ['roadmap', 'satellite', 'hybrid', 'terrain',
                    'styled_map']
          }
        });
        map.mapTypes.set('styled_map', styledMapType);
        map.setMapTypeId('styled_map');

        var geocoder = new google.maps.Geocoder();

        document.getElementById('submit').addEventListener('click', function() {
          geocodeAddress(geocoder, map);
        });
      }

      function geocodeAddress(geocoder, resultsMap) {
        var address = document.getElementById('currentCity').value;
        geocoder.geocode({'address': address}, function(results, status) {
          if (status === 'OK') {
            resultsMap.setCenter(results[0].geometry.location);
            var marker = new google.maps.Marker({
              map: resultsMap,
              position: results[0].geometry.location
            });
          } else {
            alert('Geocode was not successful for the following reason: ' + status);
          }
        });
      }
function getWeather(){
	var myUrl = "http://api.wunderground.com/api/" + APIkey + "/conditions/q/" + state + "/" + city + ".json";
	$.ajax({
		url:myUrl,
		dataType: "jsonp",
		success:function(response){
			// console.log(response);
			loadWeather(response);
		},
		error:function(response){
			alert('Try again.');
		}
	});
}
//pass city/state data when submit is clicked

function setLocation(){
	city = $('#currentCity').val();
	state = $('#currentState').val();

	if(city == null || city ==''){
		alert('You need to choose a city');
	}
	console.log("Getting weather for: " + city + "," + state);
	getWeather();
	console.log(state);
};

// init
function init(){
	console.log("hello");
	$('#submit').click(function(e){
		e.preventDefault();
		setLocation();
	});
};
// run on load
$('document').ready(function(){
	init();

});