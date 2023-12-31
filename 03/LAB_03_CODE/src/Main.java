import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.embed.swing.SwingFXUtils;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import org.opencv.core.*;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main extends Application {
    private ImageView imageView = new ImageView();
    private Mat originalImage;

    public static void main(String[] args) {
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Image Processing App");

        Button openButton = new Button("Open Image");
        openButton.setOnAction(e -> openImage());

        Button applyFilterButton = new Button("Apply Median Filter");
        applyFilterButton.setOnAction(e -> applyMedianFilter());

        Button applyMinimumFilterButton = new Button("Apply Minimum Filter");
        applyMinimumFilterButton.setOnAction(e -> applyMinimumFilter());

        Button applyMaximumFilterButton = new Button("Apply Maximum Filter");
        applyMaximumFilterButton.setOnAction(e -> applyMaximumFilter());

        Button applyOtsuButton = new Button("Apply Otsu Threshold");
        applyOtsuButton.setOnAction(e -> applyOtsuThreshold());

        Button applyGlobalThresholdButton = new Button("Apply Global Threshold");
        applyGlobalThresholdButton.setOnAction(e -> applyGlobalThreshold());

        Button applyAdaptiveThresholdButton = new Button("Apply Adaptive Threshold");
        applyAdaptiveThresholdButton.setOnAction(e -> applyAdaptiveThreshold());

        VBox buttonsBox = new VBox(10, openButton, applyFilterButton,
                applyOtsuButton, applyGlobalThresholdButton,
                applyAdaptiveThresholdButton, applyMinimumFilterButton,
                applyMaximumFilterButton);
        buttonsBox.setPadding(new Insets(10));

        ScrollPane scrollPane = new ScrollPane();
        scrollPane.setContent(imageView);
        scrollPane.setFitToHeight(true);
        scrollPane.setFitToWidth(true);

        BorderPane borderPane = new BorderPane();
        borderPane.setLeft(buttonsBox);

        VBox imageContainer = new VBox();
        imageContainer.getChildren().add(scrollPane);
        imageContainer.setBorder(new Border(new BorderStroke(Color.BLACK,
                BorderStrokeStyle.SOLID, CornerRadii.EMPTY, BorderWidths.DEFAULT)));

        borderPane.setCenter(imageContainer);

        Scene scene = new Scene(borderPane, 800, 600);

        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void openImage() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Image Files", "*.png", "*.jpg", "*.jpeg"));
        File selectedFile = fileChooser.showOpenDialog(null);

        if (selectedFile != null) {
            originalImage = Imgcodecs.imread(selectedFile.getAbsolutePath());
            showImage(originalImage);
        }
    }

    private void showImage(Mat image) {
        Image fxImage = mat2Image(image);
        imageView.setImage(fxImage);
        imageView.setPreserveRatio(true);
        ChangeListener<Number> listener = (observable, oldValue, newValue) -> {
            double width = imageView.getFitWidth();
            double height = imageView.getFitHeight();

            double scale = Math.min(width / fxImage.getWidth(), height / fxImage.getHeight());

            imageView.setFitWidth(fxImage.getWidth() * scale);
            imageView.setFitHeight(fxImage.getHeight() * scale);
        };

        imageView.fitWidthProperty().addListener(listener);
        imageView.fitHeightProperty().addListener(listener);
    }

    private void applyMedianFilter() {
        if (originalImage != null) {
            Mat medianFiltered = new Mat();

            // Преобразуем в оттенки серого, если изображение в цвете
            if (originalImage.channels() > 1) {
                Imgproc.cvtColor(originalImage, medianFiltered, Imgproc.COLOR_BGR2GRAY);
            } else {
                originalImage.copyTo(medianFiltered);
            }

            // Разделяем на каналы, если изображение не в оттенках серого
            if (medianFiltered.channels() > 1) {
                List<Mat> channels = new ArrayList<>();
                Core.split(medianFiltered, channels);

                for (Mat channel : channels) {
                    Imgproc.medianBlur(channel, channel, 5);
                }

                Core.merge(channels, medianFiltered);
            } else {
                Imgproc.medianBlur(medianFiltered, medianFiltered, 5);
            }

            showImage(medianFiltered);
        }
    }


    private void applyMinimumFilter() {
        if (originalImage != null) {
            Mat minimumFiltered = new Mat();

            // Преобразуем в оттенки серого, если изображение в цвете
            if (originalImage.channels() > 1) {
                Imgproc.cvtColor(originalImage, minimumFiltered, Imgproc.COLOR_BGR2GRAY);
            } else {
                originalImage.copyTo(minimumFiltered);
            }

            // Применяем фильтр минимума
            Imgproc.erode(minimumFiltered, minimumFiltered, new Mat());

            showImage(minimumFiltered);
        }
    }

    private void applyMaximumFilter() {
        if (originalImage != null) {
            Mat maximumFiltered = new Mat();

            // Преобразуем в оттенки серого, если изображение в цвете
            if (originalImage.channels() > 1) {
                Imgproc.cvtColor(originalImage, maximumFiltered, Imgproc.COLOR_BGR2GRAY);
            } else {
                originalImage.copyTo(maximumFiltered);
            }

            // Применяем фильтр максимума
            Imgproc.dilate(maximumFiltered, maximumFiltered, new Mat());

            showImage(maximumFiltered);
        }
    }



    private void applyOtsuThreshold() {
        if (originalImage != null) {
            Mat grayImage = new Mat();
            Imgproc.cvtColor(originalImage, grayImage, Imgproc.COLOR_BGR2GRAY);

            Mat thresholdedImage = new Mat();
            Imgproc.threshold(grayImage, thresholdedImage, 0, 255, Imgproc.THRESH_BINARY + Imgproc.THRESH_OTSU);

            showImage(thresholdedImage);
        }
    }

    private void applyGlobalThreshold() {
        if (originalImage != null) {
            Mat thresholdedImage = new Mat();
            Imgproc.cvtColor(originalImage, thresholdedImage, Imgproc.COLOR_BGR2GRAY);

            double epsilon = 1.0; // Set your desired epsilon value
            int currentThreshold = 128; // Initial threshold value
            int previousThreshold = -1;

            while (Math.abs(currentThreshold - previousThreshold) > epsilon) {
                Mat foreground = new Mat();
                Mat background = new Mat();

                Core.compare(thresholdedImage, new Scalar(currentThreshold), foreground, Core.CMP_GT);
                Core.compare(thresholdedImage, new Scalar(currentThreshold), background, Core.CMP_LE);

                Scalar foregroundMean = Core.mean(thresholdedImage, foreground);
                Scalar backgroundMean = Core.mean(thresholdedImage, background);

                previousThreshold = currentThreshold;
                currentThreshold = (int) ((foregroundMean.val[0] + backgroundMean.val[0]) / 2.0);

                Imgproc.threshold(thresholdedImage, thresholdedImage, currentThreshold, 255, Imgproc.THRESH_BINARY);
            }

            showImage(thresholdedImage);
        }
    }

    private void applyAdaptiveThreshold() {
        if (originalImage != null) {
            Mat grayImage = new Mat();
            Imgproc.cvtColor(originalImage, grayImage, Imgproc.COLOR_BGR2GRAY);

            Mat thresholdedImage = new Mat();
            Imgproc.adaptiveThreshold(
                    grayImage, thresholdedImage,
                    255, Imgproc.ADAPTIVE_THRESH_MEAN_C,
                    Imgproc.THRESH_BINARY, 3, 4
            );

            showImage(thresholdedImage);
        }
    }


    private Image mat2Image(Mat mat) {
        MatOfByte byteMat = new MatOfByte();
        Imgcodecs.imencode(".png", mat, byteMat);
        byte[] byteArray = byteMat.toArray();

        try {
            BufferedImage bufImage = ImageIO.read(new ByteArrayInputStream(byteArray));
            return SwingFXUtils.toFXImage(bufImage, null);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }
}
