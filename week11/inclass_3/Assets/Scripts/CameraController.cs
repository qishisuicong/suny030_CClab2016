using UnityEngine;
using System.Collections;

public class CameraController : MonoBehaviour {
	public GameObject player;
	private Vector3 offset;

	// Use this for initialization
	void Start () {
		offset = transform.position - player.transform.position;
	
	}
	//For Follow Cameras, Procedural Animations, etc., it's best to use LateUpdate
	//LateUpdate, runs after all items have been processed
	void LateUpdate(){
		transform.position = player.transform.position + offset;
		
	}
}
