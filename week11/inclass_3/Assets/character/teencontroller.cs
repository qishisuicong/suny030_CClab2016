using UnityEngine;
using System.Collections;

public class teencontroller : MonoBehaviour {
	private Animator animComp;
	private Rigidbody rb;

	// Use this for initialization
	void Start () {
		animComp = this.GetComponent<Animator> ();
		rb = GetComponent<Rigidbody> ();
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown (KeyCode.UpArrow)) {
			animComp.SetInteger ("state", 1);
		}
		if (Input.GetKeyUp (KeyCode.UpArrow)) {
			animComp.SetInteger ("state", 0);
		}
		if (Input.GetKeyDown (KeyCode.LeftArrow)) {
			animComp.SetInteger ("state", 2);
		}
		if (Input.GetKeyUp (KeyCode.LeftArrow)) {
			animComp.SetInteger ("state", 0);
		}
		if (Input.GetKeyDown (KeyCode.RightArrow)) {
			animComp.SetInteger ("state", 3);
		}
		if (Input.GetKeyUp (KeyCode.RightArrow)) {
			animComp.SetInteger ("state", 0);
		}
	}
	void OnTriggerEnter(Collider other){
		if (other.gameObject.CompareTag ("Pick Up")) {
			other.gameObject.SetActive (false);
		}
	}
}
	


