#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <vector>

int faceDetection(std::string output,std::string input,int scale,int permissive){

cv::VideoCapture videoCapture(output);
cv::VideoCapture inputCapture(input);
    if (!videoCapture.isOpened())
    {
        std::cout << "Failed to open input video file." << std::endl;
        return -1;
    }
std::string outputFile = "Final_"+output;
cv::VideoWriter videoWriter(outputFile, cv::VideoWriter::fourcc('m', 'p', '4', 'v'), 30,cv::Size(videoCapture.get(cv::CAP_PROP_FRAME_WIDTH), videoCapture.get(cv::CAP_PROP_FRAME_HEIGHT)));
cv::CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml"))
    {
        std::cout << "Failed to load face cascade." << std::endl;
        return -1;
    }

    cv::Mat frame,frame1;
    while (videoCapture.read(frame)&&inputCapture.read(frame1))
    {
        std::vector<cv::Rect> faces;
        cv::Mat grayFrame;

        cv::cvtColor(frame1, grayFrame, cv::COLOR_BGR2GRAY); 
     cv::equalizeHist(grayFrame, grayFrame);
        faceCascade.detectMultiScale(grayFrame,faces,scale,permissive);
        //faceCascade.detectMultiScale(grayFrame, faces, 3.1, 1, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

        for (const auto& face : faces)
        {
            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
        }

        videoWriter.write(frame);

        cv::imshow("Face Detection", frame);
        if (cv::waitKey(1) == 27)  // Press Esc to exit
        {
            break;
        }
    }

    videoCapture.release();
    videoWriter.release();
    cv::destroyAllWindows();

    return 0;

}

int main(int argc, char** argv) {
    // Check if the required arguments are provided
    if (argc < 4) {
        std::cout << "Please provide input video file path, output file name, and edge detection parameters." << std::endl;
        return -1;
    }

    // Open the input video file
    cv::VideoCapture inputVideo(argv[1]);

    // Check if the video file was opened successfully
    if (!inputVideo.isOpened()) {
        std::cout << "Could not open the video file." << std::endl;
        return -1;
    }

    // Get input video properties
    double fps = inputVideo.get(cv::CAP_PROP_FPS);
    int width = inputVideo.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = inputVideo.get(cv::CAP_PROP_FRAME_HEIGHT);

    // Get the output file name from the first integer argument
    std::string outputFileName = std::string(argv[2]) + ".mp4";
   // std::string outputFileName = "111.mp4";
    // Create the output video file
    cv::VideoWriter outputVideo(outputFileName, cv::VideoWriter::fourcc('m', 'p', '4', 'v'), fps, cv::Size(width, height), true);



    // Check if the output video file was opened successfully
    if (!outputVideo.isOpened()) {
        std::cout << "Could not create the output video file." << std::endl;
        return -1;
    }
    //face detection
    cv::CascadeClassifier cascade;
    if(!cascade.load("haarcascade_frontalface_default.xml")){
	std::cout << "fail to connect with xml";
	return -1;
    }

    // Get the edge detection parameters from the remaining command-line arguments
    std::vector<int> edgeParams;
    for (int i = 3; i < argc; i++) {
        int param = std::stoi(argv[i]);
        edgeParams.push_back(param);
    }

    // Process each frame of the input video
    cv::Mat frame, edges;
    while (inputVideo.read(frame)) {
	cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

	std::vector<cv::Rect> faces;
	cascade.detectMultiScale(gray,faces,1.5,9);

//	 for (const auto& rect : faces)
 //       {
//	            cv::rectangle(frame, rect, cv::Scalar(200, 200, 200), 2);
 //       }
        // Perform edge detection on the frame
        cv::Canny(frame, edges, edgeParams[0], edgeParams[1]);

        // Convert the edges to color
        cv::cvtColor(edges, edges, cv::COLOR_GRAY2BGR);

        // Set the edge detection color to red (255, 0, 0)
        cv::Scalar redColor(200, 20, 20);
        edges.setTo(redColor, edges);


        // Write the processed frame to the output video file
        outputVideo.write(edges);

        // Display the processed frame
        cv::imshow("Processed Frame", edges);

        // Wait for a key press
        if (cv::waitKey(10) == 27) {
            break;
        }
    }

    // Release the video file capture and writer
    inputVideo.release();
    outputVideo.release();

    // Close all OpenCV windows
    cv::destroyAllWindows();
    std::string inputName = std::string(argv[1]);
    int reduceScale = edgeParams[2];
    int permissiveLevel = edgeParams[3];

    faceDetection(outputFileName,inputName,reduceScale,permissiveLevel);

    return 0;
}

